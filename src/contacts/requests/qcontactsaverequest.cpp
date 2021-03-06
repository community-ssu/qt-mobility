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

#include "qcontactsaverequest.h"
#include "qcontactrequests_p.h"

QTM_BEGIN_NAMESPACE

/*!
  \class QContactSaveRequest
  \brief The QContactSaveRequest class allows a client to asynchronously
    request that certain contacts be saved to a contacts store.

  For a QContactSaveRequest, the resultsAvailable() signal will be emitted when
  either the individual item errors (which may be retrieved by calling errorMap()), or the resultant
  contacts (which may be retrieved by calling contacts()), are updated, as well as if
  the overall operation error (which may be retrieved by calling error()) is updated.

  Please see the class documentation of QContactAbstractRequest for more information about
  the usage of request classes and ownership semantics.

  \ingroup contacts-requests
 */

/*! Constructs a new contact save request whose parent is the specified \a parent */
QContactSaveRequest::QContactSaveRequest(QObject* parent)
    : QContactAbstractRequest(new QContactSaveRequestPrivate, parent)
{
}

/*!
  Sets the contact to be saved to \a contact.
  Equivalent to calling:
  \code
      setContacts(QList<QContact>() << contact);
  \endcode
 */
void QContactSaveRequest::setContact(const QContact& contact)
{
    Q_D(QContactSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_contacts.clear();
    d->m_contacts.append(contact);
}

/*! Sets the list of contacts to be saved to \a contacts */
void QContactSaveRequest::setContacts(const QList<QContact>& contacts)
{
    Q_D(QContactSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_contacts = contacts;
}

/*! Returns the list of contacts which will be saved if called prior to calling \c start(),
    otherwise returns the list of contacts as they were saved in the contacts store */
QList<QContact> QContactSaveRequest::contacts() const
{
    Q_D(const QContactSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_contacts;
}

/*! Returns the map of input definition list indices to errors which occurred */
QMap<int, QContactManager::Error> QContactSaveRequest::errorMap() const
{
    Q_D(const QContactSaveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_errors;
}

#include "moc_qcontactsaverequest.cpp"

QTM_END_NAMESPACE
