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
#include <QObject>
#include <QHash>
#include <qcontactfilter.h>
#include <qcontactmanager.h>
#include <cntdb.h>
#include "cntsymbianengine.h"


QTM_USE_NAMESPACE
QTM_BEGIN_NAMESPACE
typedef struct {
    QContactFilter filter;
    QString name;
    int result;
    int error;
} TFilter;
QTM_END_NAMESPACE

class TestFiltering : public QObject
{
    Q_OBJECT

private slots:  // Init & cleanup
	void initTestCase();
	void cleanupTestCase();

private:
    void parseFilters();
    void addFilter(QVector<QString> param);
    void createContacts();
    QContactFilter::MatchFlags getMatchFlag(QString& inputflag);

    void createContact_1();
    void createContact_2();
    void createContact_3();
    void createContact_4();
    void createContact_5();
private slots:  // Test cases
    void testInvalidFilter();
    void testContactDetailFilter();
    void testContactDetailRangeFilter();
    void testChangeLogFilter();
    void testRelationshipFilter();
    void testIntersectionFilter();
    void testUnionFilter();
    void testLocalIdFilter();
    void testDefaultFilter();
    void testZeroSearch();
    void testFilterSupported();
    void testCreateSelectQuery();
private:
    void  testIntersectionFilter_1();
    void  testIntersectionFilter_2();
    void  testUnionFilter_1();
    void  testUnionFilter_2();
    void  testContactDetailFilter_1();
    void  testContactDetailFilter_2();
private:
    QContactManager                             *mCntMng;
    QHash<QContactFilter::FilterType, TFilter>  *mFilters;
    CContactDatabase *m_database;
};
