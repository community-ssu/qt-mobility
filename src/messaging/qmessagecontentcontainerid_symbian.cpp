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
#include "qmessagecontentcontainerid.h"
#include <messagingutil_p.h>


QTM_BEGIN_NAMESPACE

class QMessageContentContainerIdPrivate
{
public:
    QString _id;
};

QMessageContentContainerId::QMessageContentContainerId()
: d_ptr(new QMessageContentContainerIdPrivate)
{
}

QMessageContentContainerId::QMessageContentContainerId(const QMessageContentContainerId& other)
: d_ptr(new QMessageContentContainerIdPrivate)
{
	this->operator=(other);
}

QMessageContentContainerId::QMessageContentContainerId(const QString& id)
: d_ptr(new QMessageContentContainerIdPrivate)
{
    if(!SymbianHelpers::stripIdPrefix(id).isEmpty())
        d_ptr->_id = id;
}

QMessageContentContainerId::~QMessageContentContainerId()
{
	delete d_ptr;
}

bool QMessageContentContainerId::operator==(const QMessageContentContainerId& other) const
{
	return (d_ptr->_id == other.d_ptr->_id);
}

QMessageContentContainerId& QMessageContentContainerId::operator=(const QMessageContentContainerId& other)
{
	if (&other != this) {
		d_ptr->_id = other.d_ptr->_id;
	}

    return *this;
}

QString QMessageContentContainerId::toString() const
{
    if(!isValid())
        return QString();

	return d_ptr->_id;
}

bool QMessageContentContainerId::isValid() const
{
	return !d_ptr->_id.isEmpty();
}

QTM_END_NAMESPACE
