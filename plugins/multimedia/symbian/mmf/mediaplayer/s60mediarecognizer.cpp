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

#include "S60mediarecognizer.h"
#include <e32def.h>
#include <e32cmn.h>
#include <QtCore/qurl.h>
#include <QtCore/qdir.h>
#include <QtCore/qdebug.h>

#include <apgcli.h>

static const TInt KMimeTypePrefixLength = 6; // "audio/" or "video/"
_LIT(KMimeTypePrefixAudio, "audio/");
_LIT(KMimeTypePrefixVideo, "video/");

S60MediaRecognizer::S60MediaRecognizer(QObject *parent) : QObject(parent)
{
}

S60MediaRecognizer::~S60MediaRecognizer()
{
    m_file.Close();
    m_fileServer.Close();
    m_recognizer.Close();
}

S60MediaRecognizer::MediaType S60MediaRecognizer::mediaType(const QUrl &url)
{
    bool isStream = (url.scheme() == "file")?false:true;

    if (isStream)
        return Url;
    else
        return identifyMediaType(url.toLocalFile());
}

S60MediaRecognizer::MediaType S60MediaRecognizer::identifyMediaType(const QString& fileName)
{
    S60MediaRecognizer::MediaType result = Video; // default to videoplayer
    bool recognizerOpened = false;

    TInt err = m_recognizer.Connect();
    if (err == KErrNone) {
        recognizerOpened = true;
    }

    err = m_fileServer.Connect();
    if (err == KErrNone) {
        recognizerOpened = true;
    }

    // This is needed for sharing file handles for the recognizer
    err = m_fileServer.ShareProtected();
    if (err == KErrNone) {
        recognizerOpened = true;
    }

    if (recognizerOpened) {
        m_file.Close();
        err = m_file.Open(m_fileServer, QString2TPtrC(QDir::toNativeSeparators(fileName)), EFileRead |
            EFileShareReadersOnly);

        if (err == KErrNone) {
            TDataRecognitionResult recognizerResult;
            err = m_recognizer.RecognizeData(m_file, recognizerResult);
            if (err == KErrNone) {
                const TPtrC mimeType = recognizerResult.iDataType.Des();

                if (mimeType.Left(KMimeTypePrefixLength).Compare(KMimeTypePrefixAudio) == 0) {
                    result = Audio;
                } else if (mimeType.Left(KMimeTypePrefixLength).Compare(KMimeTypePrefixVideo) == 0) {
                    result = Video;
                }
            }
        }
    }
    return result;
}

TPtrC S60MediaRecognizer::QString2TPtrC( const QString& string )
{
    // Returned TPtrC is valid as long as the given parameter is valid and unmodified
    return TPtrC16(static_cast<const TUint16*>(string.utf16()), string.length());
}
