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

#include "cntsimcontactfetchrequest.h"
#include "cntsymbiansimengine.h"
#include "cntsimstore.h"
#include <qcontactfetchrequest.h>
#include <qcontactlocalidfilter.h>

CntSimContactFetchRequest::CntSimContactFetchRequest(CntSymbianSimEngine *engine, QContactFetchRequest *req)
    :CntAbstractSimRequest(engine, req)
{
    connect( simStore(), SIGNAL(readComplete(QList<QContact>, QContactManager::Error)),
        this, SLOT(readComplete(QList<QContact>, QContactManager::Error)), Qt::QueuedConnection );
}

CntSimContactFetchRequest::~CntSimContactFetchRequest()
{
    cancel();
}

void CntSimContactFetchRequest::run()
{
    QContactFetchRequest *r = req<QContactFetchRequest>();
    
    if (!r->isActive())
        return;
    
    // Get filter
    QContactLocalIdFilter lidFilter;
    if (r->filter().type() == QContactFilter::LocalIdFilter) {
        lidFilter = static_cast<QContactLocalIdFilter>(r->filter());
    }        

    // Fetch all contacts and filter the results.
    // Contacts are fetched starting from index 1, all slots are read
    // since slots may be not filled in a sequence.
    int index = 1;
    int numSlots = simStore()->storeInfo().m_totalEntries;
    
    if (lidFilter.ids().count() == 1) {
        // Optimization for performance. Fetch a single contact from store.
        // This is mainly for CntSymbianSimEngine::contact().
        index = lidFilter.ids().at(0);
        numSlots = 1;
    } 

    QContactManager::Error error = QContactManager::NoError;    
    if (!simStore()->read(index, numSlots, &error)) {
        QContactManagerEngine::updateContactFetchRequest(r, QList<QContact>(), error, QContactAbstractRequest::FinishedState);
    }
}

void CntSimContactFetchRequest::readComplete(QList<QContact> contacts, QContactManager::Error error)    
{
    QContactFetchRequest *r = req<QContactFetchRequest>();
    
    if (!r->isActive())
        return;
    
    // Sometimes the sim store will return server busy error. All we can do is
    // wait and try again. The error seems to occur if we try to read from the
    // store right after writing some contacts to it.  
    // This was observed with S60 5.0 HW (Tube).
    if (simStore()->lastAsyncError() == KErrServerBusy) {
        if (waitAndRetry())
            return;
    }
    
    // Filter & sort results
    QList<QContact> filteredAndSorted;
    for (int i=0; i<contacts.count(); i++) {
        if (engine()->filter(r->filter(), contacts.at(i)))
            QContactManagerEngine::addSorted(&filteredAndSorted, contacts.at(i), r->sorting());
    }

    // Complete the request
    QContactManagerEngine::updateContactFetchRequest(r, filteredAndSorted, error, QContactAbstractRequest::FinishedState);
}
