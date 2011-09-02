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

#include <QCoreApplication>
#include <QStringList>
#include <QLocalSocket>
#include "../../../../src/bearer/qnetworkconfigmanager.h"
#include "../../../../src/bearer/qnetworkconfiguration.h"
#include "../../../../src/bearer/qnetworksession.h"

#include <QEventLoop>
#include <QTimer>
#include <QDebug>

QTM_USE_NAMESPACE


#define NO_DISCOVERED_CONFIGURATIONS_ERROR 1
#define SESSION_OPEN_ERROR 2


int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    // Update configurations so that everything is up to date for this process too.
    // Event loop is used to wait for awhile.
    QNetworkConfigurationManager manager;
    manager.updateConfigurations();
    QEventLoop iIgnoreEventLoop;
    QTimer::singleShot(3000, &iIgnoreEventLoop, SLOT(quit()));
    iIgnoreEventLoop.exec();

    QList<QNetworkConfiguration> discovered =
        manager.allConfigurations(QNetworkConfiguration::Discovered);

        foreach(QNetworkConfiguration config, discovered) {
            qDebug() << "Lackey: Name of the config enumerated: " << config.name();
            qDebug() << "Lackey: State of the config enumerated: " << config.state();
        }

    if (discovered.isEmpty()) {
        qDebug("Lackey: no discovered configurations, returning empty error.");
        return NO_DISCOVERED_CONFIGURATIONS_ERROR;
    }

    // Cannot read/write to processes on WinCE or Symbian.
    // Easiest alternative is to use sockets for IPC.
    QLocalSocket oopSocket;

    oopSocket.connectToServer("tst_qnetworksession");
    oopSocket.waitForConnected(-1);

    qDebug() << "Lackey started";

    QNetworkSession *session = 0;
    do {
        if (session) {
            delete session;
            session = 0;
        }

        qDebug() << "Discovered configurations:" << discovered.count();

        if (discovered.isEmpty()) {
            qDebug() << "No more discovered configurations";
            break;
        }

        qDebug() << "Taking first configuration";

        QNetworkConfiguration config = discovered.takeFirst();

        if ((config.state() & QNetworkConfiguration::Active) == QNetworkConfiguration::Active) {
            qDebug() << config.name() << " is active, therefore skipping it (looking for configs in 'discovered' state).";
            continue;
        }

        qDebug() << "Creating session for" << config.name() << config.identifier();

        session = new QNetworkSession(config);

        QString output = QString("Starting session for %1\n").arg(config.identifier());
        oopSocket.write(output.toAscii());
        oopSocket.waitForBytesWritten();
        session->open();
        session->waitForOpened();
    } while (!(session && session->isOpen()));

    qDebug() << "lackey: loop done";

    if (!session) {
        qDebug() << "Could not start session";

        oopSocket.disconnectFromServer();
        oopSocket.waitForDisconnected(-1);

        return SESSION_OPEN_ERROR;
    }

    QString output = QString("Started session for %1\n").arg(session->configuration().identifier());
    oopSocket.write(output.toAscii());
    oopSocket.waitForBytesWritten();

    oopSocket.waitForReadyRead();
    oopSocket.readLine();

    session->stop();

    delete session;

    oopSocket.disconnectFromServer();
    oopSocket.waitForDisconnected(-1);

    return 0;
}
