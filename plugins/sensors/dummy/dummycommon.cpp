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

#include "dummycommon.h"

#ifdef Q_OS_WINCE
#include <windows.h>
// WINCE has <time.h> but using clock() gives a link error because
// the function isn't actually implemented.
#else
#include <time.h>
#endif

dummycommon::dummycommon(QSensor *sensor)
    : QSensorBackend(sensor)
    , m_timerid(0)
{
}

void dummycommon::start()
{
    if (m_timerid)
        return;

    int dataRate = sensor()->dataRate();
    if (dataRate == 0) {
        if (sensor()->availableDataRates().count())
            // Use the first available rate when -1 is chosen
            dataRate = sensor()->availableDataRates().first().first;
        else
            dataRate = 1;
    }

    int interval = 1000 / dataRate;

    if (interval)
        m_timerid = startTimer(interval);
}

void dummycommon::stop()
{
    if (m_timerid) {
        killTimer(m_timerid);
        m_timerid = 0;
    }
}

void dummycommon::timerEvent(QTimerEvent * /*event*/)
{
    poll();
}

qtimestamp getTimestamp()
{
#ifdef Q_OS_WINCE
    // This implementation is based on code found here:
    // http://social.msdn.microsoft.com/Forums/en/vssmartdevicesnative/thread/74870c6c-76c5-454c-8533-812cfca585f8
    HANDLE currentThread = GetCurrentThread();
    FILETIME creationTime, exitTime, kernalTime, userTime;
    GetThreadTimes(currentThread, &creationTime, &exitTime, &kernalTime, &userTime);

    ULARGE_INTEGER uli;
    uli.LowPart = userTime.dwLowDateTime;
    uli.HighPart = userTime.dwHighDateTime;
    ULONGLONG systemTimeInMS = uli.QuadPart/10000;
    return static_cast<qtimestamp>(systemTimeInMS);
#else
    return clock();
#endif
}

