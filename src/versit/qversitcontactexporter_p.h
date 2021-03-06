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

#ifndef QVERSITCONTACTEXPORTER_P_H
#define QVERSITCONTACTEXPORTER_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qversitdocument.h"
#include "qversitproperty.h"
#include "qmobilityglobal.h"

#include <QHash>
#include <QObject>

QTM_BEGIN_NAMESPACE
class QContact;
class QContactDetail;

class Q_AUTOTEST_EXPORT QVersitContactExporterPrivate
{
public:
    QVersitContactExporterPrivate();
    ~QVersitContactExporterPrivate();

    bool exportContact(const QContact& contact, QVersitDocument& versitDocument,
                       QVersitContactExporter::Error* error);

protected:
    static bool documentContainsName(const QVersitDocument& document);
    void encodeName(QVersitProperty& property, const QContactDetail& detail);
    void encodePhoneNumber(QVersitProperty& property, const QContactDetail& detail);
    void encodeEmail(QVersitProperty& property, const QContactDetail& detail);
    void encodeAddress(QVersitProperty& property, const QContactDetail& detail);
    void encodeUrl(QVersitProperty& property, const QContactDetail& detail);
    void encodeUid(QVersitProperty& property, const QContactDetail& detail);
    bool encodeRev(QVersitProperty& property, const QContactDetail& detail);
    void encodeBirthDay(QVersitProperty& property, const QContactDetail& detail);
    void encodeNote(QVersitProperty& property, const QContactDetail& detail);
    void encodeGeoLocation(QVersitProperty& property, const QContactDetail& detail);
    void encodeOrganization(QVersitDocument& document, const QContactDetail& detail);
    void encodeGender(QVersitProperty& property, const QContactDetail& detail);
    void encodeNickname(QVersitDocument& document, const QContactDetail& detail);
    void encodeTag(QVersitDocument& document, const QContactDetail& detail);
    void encodeAnniversary(QVersitProperty& property, const QContactDetail& detail);
    bool encodeOnlineAccount(QVersitProperty& property, const QContactDetail& detail);
    bool encodeFamily(QVersitDocument& document, const QContactDetail& detail);
    bool encodeRingtone(QVersitProperty& property, const QContactDetail& detail);
    bool encodeThumbnail(QVersitProperty& property, const QContactDetail& detail);
    bool encodeAvatar(QVersitProperty& property, const QContactDetail& detail);
    bool encodeDisplayLabel(QVersitProperty& property,
        const QContactDetail& detail,
        const QContact& contact);
    bool isValidRemoteUrl(const QString& resourceIdentifier);
    void encodeParameters(QVersitProperty& property,
        const QStringList& contexts,
        const QStringList& subTypes=QStringList());
    bool encodeContentFromFile(const QString& resourcePath, QVersitProperty& property);

public: // Data
    QList<QVersitDocument> mDocuments;
    QMap<int, QVersitContactExporter::Error> mErrors;
    QVersitContactExporterDetailHandler* mDetailHandler;
    QVersitDefaultResourceHandler* mDefaultResourceHandler;
    QVersitResourceHandler* mResourceHandler;
    QHash<QString,QString> mPropertyMappings;
    QHash<QString,QString> mParameterMappings;
    QVersitDocument::VersitType mVersitType;
};

QTM_END_NAMESPACE

#endif // QVERSITCONTACTEXPORTER_P_H
