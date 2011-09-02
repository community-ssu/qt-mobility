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

#include "qvideowindowcontrol.h"

QT_BEGIN_NAMESPACE

/*!
    \class QVideoWindowControl
    \preliminary
    \ingroup multimedia
    \brief The QVideoWindowControl class provides a media control for rendering video to a window.


    The winId() property QVideoWindowControl allows a platform specific window
    ID to be set as the video render target of a QMediaService.  The
    displayRect() property is used to set the region of the window the video
    should be rendered to, and the aspectRatioMode() property indicates how the
    video should be scaled to fit the displayRect().

    \code
    QVideoWindowControl *windowControl = mediaService->requestControl<QVideoWindowControl *>();
    windowControl->setWinId(widget->winId());
    windowControl->setDisplayRect(widget->rect());
    windowControl->setAspectRatioMode(Qt::KeepAspectRatio);
    \endcode

    QVideoWindowControl is one of number of possible video output controls.

    The interface name of QVideoWindowControl is \c com.nokia.Qt.QVideoWindowControl/1.0 as
    defined in QVideoWindowControl_iid.

    \sa QMediaService::requestControl(), QVideoWidget
*/

/*!
    \macro QVideoWindowControl_iid

    \c com.nokia.Qt.QVideoWindowControl/1.0

    Defines the interface name of the QVideoWindowControl class.

    \relates QVideoWindowControl
*/

/*!
    Constructs a new video window control with the given \a parent.
*/
QVideoWindowControl::QVideoWindowControl(QObject *parent)
    : QMediaControl(parent)
{
}

/*!
    Destroys a video window control.
*/
QVideoWindowControl::~QVideoWindowControl()
{
}

/*!
    \fn QVideoWindowControl::winId() const

    Returns the ID of the window a video overlay end point renders to.
*/

/*!
    \fn QVideoWindowControl::setWinId(WId id)

    Sets the \a id of the window a video overlay end point renders to.
*/

/*!
    \fn QVideoWindowControl::displayRect() const
    Returns the sub-rect of a window where video is displayed.
*/

/*!
    \fn QVideoWindowControl::setDisplayRect(const QRect &rect)
    Sets the sub-\a rect of a window where video is displayed.
*/

/*!
    \fn QVideoWindowControl::isFullScreen() const

    Identifies if a video overlay is a fullScreen overlay.

    Returns true if the video overlay is fullScreen, and false otherwise.
*/

/*!
    \fn QVideoWindowControl::setFullScreen(bool fullScreen)

    Sets whether a video overlay is a \a fullScreen overlay.
*/

/*!
    \fn QVideoWindowControl::fullScreenChanged(bool fullScreen)

    Signals that the \a fullScreen state of a video overlay has changed.
*/

/*!
    \fn QVideoWindowControl::repaint()

    Repaints the last frame.
*/

/*!
    \fn QVideoWindowControl::nativeSize() const

    Returns a suggested size for the video display based on the resolution and aspect ratio of the
    video.
*/

/*!
    \fn QVideoWindowControl::nativeSizeChanged()

    Signals that the native dimensions of the video have changed.
*/


/*!
    \fn QVideoWindowControl::aspectRatioMode() const

    Returns how video is scaled to fit the display region with respect to its aspect ratio.
*/

/*!
    \fn QVideoWindowControl::setAspectRatioMode(Qt::AspectRatioMode mode)

    Sets the aspect ratio \a mode which determines how video is scaled to the fit the display region
    with respect to its aspect ratio.
*/

/*!
    \fn QVideoWindowControl::brightness() const

    Returns the brightness adjustment applied to a video overlay.

    Valid brightness values range between -100 and 100, the default is 0.
*/

/*!
    \fn QVideoWindowControl::setBrightness(int brightness)

    Sets a \a brightness adjustment for a video overlay.

    Valid brightness values range between -100 and 100, the default is 0.
*/

/*!
    \fn QVideoWindowControl::brightnessChanged(int brightness)

    Signals that a video overlay's \a brightness adjustment has changed.
*/

/*!
    \fn QVideoWindowControl::contrast() const

    Returns the contrast adjustment applied to a video overlay.

    Valid contrast values range between -100 and 100, the default is 0.
*/

/*!
    \fn QVideoWindowControl::setContrast(int contrast)

    Sets the \a contrast adjustment for a video overlay.

    Valid contrast values range between -100 and 100, the default is 0.
*/

/*!
    \fn QVideoWindowControl::contrastChanged(int contrast)

    Signals that a video overlay's \a contrast adjustment has changed.
*/

/*!
    \fn QVideoWindowControl::hue() const

    Returns the hue adjustment applied to a video overlay.

    Value hue values range between -100 and 100, the default is 0.
*/

/*!
    \fn QVideoWindowControl::setHue(int hue)

    Sets a \a hue adjustment for a video overlay.

    Valid hue values range between -100 and 100, the default is 0.
*/

/*!
    \fn QVideoWindowControl::hueChanged(int hue)

    Signals that a video overlay's \a hue adjustment has changed.
*/

/*!
    \fn QVideoWindowControl::saturation() const

    Returns the saturation adjustment applied to a video overlay.

    Value saturation values range between -100 and 100, the default is 0.
*/

/*!
    \fn QVideoWindowControl::setSaturation(int saturation)
    Sets a \a saturation adjustment for a video overlay.

    Valid saturation values range between -100 and 100, the default is 0.
*/

/*!
    \fn QVideoWindowControl::saturationChanged(int saturation)

    Signals that a video overlay's \a saturation adjustment has changed.
*/

#include "moc_qvideowindowcontrol.cpp"
QT_END_NAMESPACE

