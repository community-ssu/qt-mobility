/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
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

#include <math.h>

#include <QObject>
#include <QMainWindow>
#include <QIODevice>
#include <QTimer>
#include <QPushButton>
#include <QComboBox>
#include <QByteArray>

#include <qaudiooutput.h>

class Generator : public QIODevice
{
    Q_OBJECT
public:
    Generator(const QAudioFormat &format, qint64 durationUs, int frequency, QObject *parent);
    ~Generator();

    void start();
    void stop();

    qint64 readData(char *data, qint64 maxlen);
    qint64 writeData(const char *data, qint64 len);
    qint64 bytesAvailable() const;

private:
    void generateData(const QAudioFormat &format, qint64 durationUs, int frequency);

private:
    qint64 m_pos;
    QByteArray m_buffer;
};

class AudioTest : public QMainWindow
{
    Q_OBJECT
public:
    AudioTest();
    ~AudioTest();

private:
    void initializeWindow();
    void initializeAudio();
    void createAudioOutput();

private:
    QTimer*          m_pullTimer;

    // Owned by layout
    QPushButton*     m_modeButton;
    QPushButton*     m_suspendResumeButton;
    QComboBox*       m_deviceBox;

    QAudioDeviceInfo m_device;
    Generator*       m_generator;
    QAudioOutput*    m_audioOutput;
    QIODevice*       m_output; // not owned
    QAudioFormat     m_format;

    bool             m_pullMode;
    QByteArray       m_buffer;

    static const QString PushModeLabel;
    static const QString PullModeLabel;
    static const QString SuspendLabel;
    static const QString ResumeLabel;

private slots:
    void notified();
    void pullTimerExpired();
    void toggleMode();
    void toggleSuspendResume();
    void stateChanged(QAudio::State state);
    void deviceChanged(int index);
};

