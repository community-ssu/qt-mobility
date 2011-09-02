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

#include "qmediastreamscontrol.h"
#include "qmediacontrol_p.h"

QT_BEGIN_NAMESPACE

/*!
    \class QMediaStreamsControl
    \preliminary
    \ingroup multimedia
    \brief The QMediaStreamsControl class provides a media stream selection control.

    \ingroup multimedia

    The QMediaStreamsControl class provides descriptions of the available media streams
    and allows individual streams to be activated and deactivated.

    The interface name of QMediaStreamsControl is \c com.nokia.Qt.MediaStreamsControl as
    defined in QMediaStreamsControl_iid.

    \sa QMediaService::requestControl()
*/

/*!
    \macro QMediaStreamsControl_iid

    \c com.nokia.Qt.MediaStreamsControl

    Defines the interface name of the QMediaStreamsControl class.

    \relates QMediaStreamsControl
*/

/*!
    Constructs a new media streams control with the given \a parent.
*/
QMediaStreamsControl::QMediaStreamsControl(QObject *parent)
    :QMediaControl(*new QMediaControlPrivate, parent)
{
}

/*!
    Destroys a media streams control.
*/
QMediaStreamsControl::~QMediaStreamsControl()
{
}

/*!
  \enum QMediaStreamsControl::StreamType

  Media stream type.

  \value AudioStream Audio stream.
  \value VideoStream Video stream.
  \value SubPictureStream Subpicture or teletext stream.
  \value UnknownStream The stream type is unknown.
  \value DataStream
*/

/*!
    \fn QMediaStreamsControl::streamCount()

    Returns the number of media streams.
*/

/*!
    \fn QMediaStreamsControl::streamType(int stream)

    Return the type of a media \a stream.
*/

/*!
    \fn QMediaStreamsControl::metaData(int stream, QtMultimediaKit::MetaData key)

    Returns the meta-data value of \a key for a given \a stream.

    Useful metadata keya are QtMultimediaKit::Title, QtMultimediaKit::Description and QtMultimediaKit::Language.
*/

/*!
    \fn QMediaStreamsControl::isActive(int stream)

    Returns true if the media \a stream is active.
*/

/*!
    \fn QMediaStreamsControl::setActive(int stream, bool state)

    Sets the active \a state of a media \a stream.

    Setting the active state of a media stream to true will activate it.  If any other stream
    of the same type was previously active it will be deactivated. Setting the active state fo a
    media stream to false will deactivate it.
*/

/*!
    \fn QMediaStreamsControl::streamsChanged()

    The signal is emited when the available streams list is changed.
*/

/*!
    \fn QMediaStreamsControl::activeStreamsChanged()

    The signal is emited when the active streams list is changed.
*/

#include "moc_qmediastreamscontrol.cpp"
QT_END_NAMESPACE

