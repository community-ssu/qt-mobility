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

// this class is for helping qdbus get stuff

#include "qnmdbushelper_p.h"

#if !defined(QT_NO_DBUS) && !defined(Q_OS_MAC)
#include "qnetworkmanagerservice_p.h"

#include <QDBusError>
#include <QDBusInterface>
#include <QDBusMessage>
#include <QDBusReply>
#endif

#include <QDebug>

QTM_BEGIN_NAMESPACE


QNmDBusHelper::QNmDBusHelper(QObject * parent)
        : QObject(parent)
{
}

QNmDBusHelper::~QNmDBusHelper()
{
}

void QNmDBusHelper::deviceStateChanged(quint32 state)
 {
    QDBusMessage msg = this->message();
    if(state == NM_DEVICE_STATE_ACTIVATED
       || state == NM_DEVICE_STATE_DISCONNECTED
       || state == NM_DEVICE_STATE_UNAVAILABLE
       || state == NM_DEVICE_STATE_FAILED) {
        emit pathForStateChanged(msg.path(), state);
    }
 }

void QNmDBusHelper::slotAccessPointAdded(QDBusObjectPath path)
{
    if(path.path().length() > 2) {
        QDBusMessage msg = this->message();
        emit pathForAccessPointAdded(msg.path(), path);
    }
}

void QNmDBusHelper::slotAccessPointRemoved(QDBusObjectPath path)
{
    if(path.path().length() > 2) {
        QDBusMessage msg = this->message();
        emit pathForAccessPointRemoved(msg.path(), path);
    }
}

void QNmDBusHelper::slotPropertiesChanged(QMap<QString,QVariant> map)
{
    QDBusMessage msg = this->message();
    QMapIterator<QString, QVariant> i(map);
    while (i.hasNext()) {
        i.next();
        if( i.key() == "State") { //state only applies to device interfaces
            quint32 state = i.value().toUInt();
            if( state == NM_DEVICE_STATE_ACTIVATED
                || state == NM_DEVICE_STATE_DISCONNECTED
                || state == NM_DEVICE_STATE_UNAVAILABLE
                || state == NM_DEVICE_STATE_FAILED) {
                emit  pathForPropertiesChanged( msg.path(), map);
            }
        } else if( i.key() == "ActiveAccessPoint") {
            //            qWarning()  << __PRETTY_FUNCTION__ << i.key() << ": " << i.value().value<QDBusObjectPath>().path();
            //      } else if( i.key() == "Strength")
            //            qWarning()  << __PRETTY_FUNCTION__ << i.key() << ": " << i.value().toUInt();
            //   else
            //            qWarning()  << __PRETTY_FUNCTION__ << i.key() << ": " << i.value();
        }
    }
}

void QNmDBusHelper::slotSettingsRemoved()
{
    QDBusMessage msg = this->message();
    emit pathForSettingsRemoved(msg.path());
}

#include "moc_qnmdbushelper_p.cpp"
QTM_END_NAMESPACE
