/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Mobility Components.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Solutions Commercial License Agreement provided
** with the Software or, alternatively, in accordance with the terms
** contained in a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** Please note Third Party Software included with Qt Solutions may impose
** additional restrictions and it is the user's responsibility to ensure
** that they have met the licensing requirements of the GPL, LGPL, or Qt
** Solutions Commercial license and the relevant license of the Third
** Party Software they are using.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qgeopositioninfosource_maemo5_p.h"
#include "liblocationwrapper_p.h"

using namespace std;

QTM_BEGIN_NAMESPACE

QGeoPositionInfoSourceMaemo::QGeoPositionInfoSourceMaemo(QObject *parent) 
    : QGeoPositionInfoSource(parent)
{
    // default values
    availableMethods = SatellitePositioningMethods;
    
    timerInterval = DEFAULT_UPDATE_INTERVAL;
    updateTimer = new QTimer(this);
    updateTimer->setSingleShot(true);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(newPositionUpdate()));

    requestTimer = new QTimer(this);
    requestTimer->setSingleShot(true);
    connect(requestTimer, SIGNAL(timeout()), this, SLOT(requestTimeoutElapsed()));

    errorOccurred = false;
    errorSent = false;

    positionInfoState = QGeoPositionInfoSourceMaemo::Undefined;
}

int QGeoPositionInfoSourceMaemo::init()
{
    if (LiblocationWrapper::instance()->inited()) {
        connect(LiblocationWrapper::instance(), SIGNAL(error()), this, SLOT(error()));
        return INIT_OK;
    } else {
        return INIT_FAILED;
    }
}

QGeoPositionInfo QGeoPositionInfoSourceMaemo::lastKnownPosition(bool fromSatellitePositioningMethodsOnly) const
{
    return (LiblocationWrapper::instance()->lastKnownPosition(fromSatellitePositioningMethodsOnly));
}

QGeoPositionInfoSource::PositioningMethods QGeoPositionInfoSourceMaemo::supportedPositioningMethods() const
{
    return availableMethods;
}

void QGeoPositionInfoSourceMaemo::setUpdateInterval(int msec)
{
    bool updateTimerInterval = false;

    if (positionInfoState & QGeoPositionInfoSourceMaemo::PowersaveActive)
        if (positionInfoState & QGeoPositionInfoSourceMaemo::Stopped)
            updateTimerInterval = true;

    if (!msec) {
        timerInterval = MINIMUM_UPDATE_INTERVAL;
        QGeoPositionInfoSource::setUpdateInterval(0);
    } else {
        timerInterval = (msec < MINIMUM_UPDATE_INTERVAL) ? MINIMUM_UPDATE_INTERVAL : msec;
        QGeoPositionInfoSource::setUpdateInterval(timerInterval);
    }

    if (timerInterval >= POWERSAVE_THRESHOLD)
        positionInfoState |= QGeoPositionInfoSourceMaemo::PowersaveActive;
    else
        positionInfoState &= ~QGeoPositionInfoSourceMaemo::PowersaveActive;

    // If powersave has been active when new update interval has been set,
    // ensure that timer is started.
    if(updateTimerInterval)
        startLocationDaemon();

    // Ensure that new timer interval is taken into use immediately.
    activateTimer();
}

void QGeoPositionInfoSourceMaemo::setPreferredPositioningMethods(PositioningMethods sources)
{
    Q_UNUSED(sources)
    return;
}

int QGeoPositionInfoSourceMaemo::minimumUpdateInterval() const
{
    return MINIMUM_UPDATE_INTERVAL;
}

// public slots:
void QGeoPositionInfoSourceMaemo::startUpdates()
{
    startLocationDaemon();

    // Ensure that powersave is selected, if stopUpdates() has been called,
    // but selected update interval is still greater than POWERSAVE_THRESHOLD.
    if (timerInterval >= POWERSAVE_THRESHOLD)
        positionInfoState |= QGeoPositionInfoSourceMaemo::PowersaveActive;

    activateTimer();
}

void QGeoPositionInfoSourceMaemo::stopUpdates()
{
    positionInfoState &= ~QGeoPositionInfoSourceMaemo::PowersaveActive;
    
    if (!(positionInfoState & QGeoPositionInfoSourceMaemo::RequestActive)) {
        updateTimer->stop();
        if (LiblocationWrapper::instance()->isActive())
            LiblocationWrapper::instance()->stop();
    }

    errorOccurred = false;
    errorSent = false;

    positionInfoState &= ~QGeoPositionInfoSourceMaemo::Started;
    positionInfoState |= QGeoPositionInfoSourceMaemo::Stopped;
}

void QGeoPositionInfoSourceMaemo::requestUpdate(int timeout)
{
    int timeoutForRequest = 0;

    if (!timeout) {
        if (LiblocationWrapper::instance()->isActive())
            // If GPS is active, assume quick fix.
            timeoutForRequest = DEFAULT_UPDATE_INTERVAL;
        else
            // Otherwise reserve longer time to get a fix.
            timeoutForRequest = POWERSAVE_POWERON_PERIOD;
    } else if (timeout < MINIMUM_UPDATE_INTERVAL) {
        if (positionInfoState & QGeoPositionInfoSourceMaemo::RequestActive)
            return;

        emit updateTimeout();
        return;
    } else {
        timeoutForRequest = timeout;
    }

    positionInfoState |= QGeoPositionInfoSourceMaemo::RequestActive;

    if (!(LiblocationWrapper::instance()->isActive()))
        LiblocationWrapper::instance()->start();

    activateTimer();
    requestTimer->start(timeoutForRequest);
}

void QGeoPositionInfoSourceMaemo::newPositionUpdate()
{
    if (LiblocationWrapper::instance()->fixIsValid()) {
        errorOccurred = false;
        errorSent = false;

        if (positionInfoState & QGeoPositionInfoSourceMaemo::RequestActive) {
            positionInfoState &= ~QGeoPositionInfoSourceMaemo::RequestActive;
            requestTimer->stop();

            if (positionInfoState & QGeoPositionInfoSourceMaemo::Stopped)
                if (LiblocationWrapper::instance()->isActive())
                    LiblocationWrapper::instance()->stop();

            // Ensure that requested position fix is emitted even though
            // powersave is active and GPS would normally be off.
            if ((positionInfoState & QGeoPositionInfoSourceMaemo::PowersaveActive) &&
               (positionInfoState & QGeoPositionInfoSourceMaemo::Stopped)) {
                emit positionUpdated(LiblocationWrapper::instance()->position());
            }
        }

        // Make sure that if update is triggered when waking up, there
        // is no false position update.
        if (!((positionInfoState & QGeoPositionInfoSourceMaemo::PowersaveActive) &&
             (positionInfoState & QGeoPositionInfoSourceMaemo::Stopped)))
            emit positionUpdated(LiblocationWrapper::instance()->position());
    } else {
        // if an error occurs when we are updating periodically and we haven't 
        // sent an error since the last fix...
        if (!(positionInfoState & QGeoPositionInfoSourceMaemo::RequestActive) && 
            errorOccurred && !errorSent) {
            errorSent = true;
            // we need to emit the updateTimeout signal
            emit updateTimeout();
        }
    }
    activateTimer();
}

void QGeoPositionInfoSourceMaemo::requestTimeoutElapsed()
{
    updateTimer->stop();
    emit updateTimeout();

    positionInfoState &= ~QGeoPositionInfoSourceMaemo::RequestActive;

    if (positionInfoState & QGeoPositionInfoSourceMaemo::Stopped)
        if (LiblocationWrapper::instance()->isActive())
            LiblocationWrapper::instance()->stop();   

    activateTimer();
}

void QGeoPositionInfoSourceMaemo::error()
{
    errorOccurred = true;
}

void QGeoPositionInfoSourceMaemo::activateTimer() {
    if (positionInfoState & QGeoPositionInfoSourceMaemo::RequestActive) {
        updateTimer->start(MINIMUM_UPDATE_INTERVAL);
        return;
    }
    
    if (positionInfoState & QGeoPositionInfoSourceMaemo::PowersaveActive) {
        if (positionInfoState & QGeoPositionInfoSourceMaemo::Started) {
            // Cannot call stopUpdates() here since we want to keep powersave
            // active.
            if (LiblocationWrapper::instance()->isActive())
                LiblocationWrapper::instance()->stop();
            updateTimer->start(timerInterval - POWERSAVE_POWERON_PERIOD);
            errorOccurred = false;
            errorSent = false;

            positionInfoState &= ~QGeoPositionInfoSourceMaemo::Started;
            positionInfoState |= QGeoPositionInfoSourceMaemo::Stopped;
        } else if (positionInfoState & QGeoPositionInfoSourceMaemo::Stopped) {
            startLocationDaemon();
            updateTimer->start(POWERSAVE_POWERON_PERIOD);
        }
        return;
    }

    if (positionInfoState & QGeoPositionInfoSourceMaemo::Started)
        updateTimer->start(timerInterval);
}

void QGeoPositionInfoSourceMaemo::startLocationDaemon() {
    if (!(LiblocationWrapper::instance()->isActive()))
        LiblocationWrapper::instance()->start();
    positionInfoState |= QGeoPositionInfoSourceMaemo::Started;
    positionInfoState &= ~QGeoPositionInfoSourceMaemo::Stopped;
}

#include "moc_qgeopositioninfosource_maemo5_p.cpp"
QTM_END_NAMESPACE

