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

#ifndef QSOUNDEFFECT_PULSE_H
#define QSOUNDEFFECT_PULSE_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API. It exists purely as an
// implementation detail. This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//


#include "qsoundeffect.h"

#include <QtCore/qobject.h>
#include <QtCore/qdatetime.h>
#include <qmediaplayer.h>
#include <pulse/pulseaudio.h>


QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

class QNetworkReply;
class QNetworkAccessManager;
class WaveDecoder;

class QSoundEffectPrivate : public QObject
{
    Q_OBJECT
public:
    explicit QSoundEffectPrivate(QObject* parent);
    ~QSoundEffectPrivate();

    QUrl source() const;
    void setSource(const QUrl &url);
    int loopCount() const;
    void setLoopCount(int loopCount);
    int volume() const;
    void setVolume(int volume);
    bool isMuted() const;
    void setMuted(bool muted);

public Q_SLOTS:
    void play();

Q_SIGNALS:
    void volumeChanged();
    void mutedChanged();

private Q_SLOTS:
    void decoderReady();
    void decoderError();
    void checkPlayTime();
    void uploadSample();

private:
    void loadSample();
    void unloadSample();
    void playSample();

    void timerEvent(QTimerEvent *event);

    static void stream_write_callback(pa_stream *s, size_t length, void *userdata);
    static void stream_state_callback(pa_stream *s, void *userdata);
    static void play_callback(pa_context *c, int success, void *userdata);

    pa_stream *m_pulseStream;

    bool    m_retry;
    bool    m_muted;
    bool    m_playQueued;
    bool    m_sampleLoaded;
    int     m_volume;
    int     m_duration;
    int     m_dataUploaded;
    int     m_loopCount;
    int     m_runningCount;
    QUrl    m_source;
    QTime  m_playbackTime;
    QByteArray m_name;
    QNetworkReply *m_reply;
    WaveDecoder *m_waveDecoder;
    QIODevice *m_stream;
    QNetworkAccessManager *m_networkAccessManager;
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QSOUNDEFFECT_PULSE_H
