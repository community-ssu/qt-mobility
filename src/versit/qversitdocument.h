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

#ifndef QVERSITDOCUMENT_H
#define QVERSITDOCUMENT_H

#include "qmobilityglobal.h"

#include <QList>
#include <QSharedDataPointer>
#include <QVariant>
#include <QDebug>

QT_BEGIN_NAMESPACE
class QTextCodec;
QT_END_NAMESPACE

QTM_BEGIN_NAMESPACE

class QVersitDocumentPrivate;
class QVersitProperty;

class Q_VERSIT_EXPORT QVersitDocument
{
public:
    enum VersitType {
        InvalidType,
        VCard21Type,   // vCard version 2.1
        VCard30Type    // vCard version 3.0 (RFC 2426)
    };

    QVersitDocument();
    QVersitDocument(const QVersitDocument& other);
    QVersitDocument(VersitType type);
    ~QVersitDocument();

    QVersitDocument& operator=(const QVersitDocument& other);
    bool operator==(const QVersitDocument& other) const;
    bool operator!=(const QVersitDocument& other) const;

    // metadata about the versit document itself.
    void setType(VersitType type);
    VersitType type() const;

    void addProperty(const QVersitProperty& property);
    void removeProperty(const QVersitProperty& property);
    void removeProperties(const QString& name);
    QList<QVersitProperty> properties() const;

    bool isEmpty() const;
    void clear();

private:

    QSharedDataPointer<QVersitDocumentPrivate> d;
};

Q_VERSIT_EXPORT uint qHash(const QVersitDocument& key);
#ifndef QT_NO_DEBUG_STREAM
Q_VERSIT_EXPORT QDebug operator<<(QDebug dbg, const QVersitDocument& property);
#endif

QTM_END_NAMESPACE

Q_DECLARE_METATYPE(QTM_PREPEND_NAMESPACE(QVersitDocument))

#endif // QVERSITDOCUMENT_H
