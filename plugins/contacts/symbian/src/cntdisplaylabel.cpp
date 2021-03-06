/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtCore module of the Qt Toolkit.
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

#include "cntdisplaylabel.h"
#include <qtcontacts.h>

/*! 
 * Constructor
 */

CntDisplayLabel::CntDisplayLabel()
{
    setDisplayLabelDetails();
}

/*! 
 * Destructor
 */
CntDisplayLabel::~CntDisplayLabel()
{
}

/*! 
 * Sets the fields that should be used for displaylabel
 * 
 * The order is defined in the QList of preferred options
 * Whereas the QPair includes the fields that should be used for 
 * the specific detail
 */
void CntDisplayLabel::setDisplayLabelDetails()
{
    //This will be variated in the future
    //adds the contact's details definition names + fields to be used for display name and filtering display label

    //Display label details
    //Contact
    //Preferred details
    QList<QPair<QLatin1String, QLatin1String> > contactPrefferedDisplayLabelDetails;
    contactPrefferedDisplayLabelDetails.append(qMakePair(QLatin1String(QContactName::DefinitionName), QLatin1String(QContactName::FieldFirstName)));
    contactPrefferedDisplayLabelDetails.append(qMakePair(QLatin1String(QContactName::DefinitionName), QLatin1String(QContactName::FieldLastName)));
    m_contactDisplayLabelDetails.append(contactPrefferedDisplayLabelDetails);

    //if preferred details doesn't exist use these
    QList<QPair<QLatin1String, QLatin1String> > contactSecondaryDisplayLabelDetails;
    contactSecondaryDisplayLabelDetails.append(qMakePair(QLatin1String(QContactOrganization::DefinitionName), QLatin1String(QContactOrganization::FieldName)));
    m_contactDisplayLabelDetails.append(contactSecondaryDisplayLabelDetails);
    
    //Group
    QList<QPair<QLatin1String, QLatin1String> > preferredGroupDisplayLabelDetails;
    preferredGroupDisplayLabelDetails.append(qMakePair(QLatin1String(QContactName::DefinitionName), QLatin1String(QContactName::FieldCustomLabel)));
    m_groupDisplayLabelDetails.append(preferredGroupDisplayLabelDetails);
}

/*! 
 * Returns a synthesised display label of a contact
 * \a contact to read the data from .
 * \a error On return, contains the possible error.
 * \return synthesised display label 
 */
QString CntDisplayLabel::synthesizedDisplayLabel(const QContact& contact, QContactManager::Error* error) const
{
    QString displayLabel;
    *error = QContactManager::NoError;
    
    //contact
    if(contact.type() == QContactType::TypeContact) {
        displayLabel = generateDisplayLabel(contact, m_contactDisplayLabelDetails);    
    }
    
    //group
    else if (contact.type() == QContactType::TypeGroup) {
        displayLabel = generateDisplayLabel(contact, m_groupDisplayLabelDetails);
    } 
    
    //invalid type
    else {
        *error = QContactManager::InvalidContactTypeError;
    }
    
    return displayLabel;
}

/*! 
 * Generate the display label
 * \a contact to read the data from .
 * \a detailList contains the details to be read from the contact
 * \return synthesised display label 
 */
QString CntDisplayLabel::generateDisplayLabel( const QContact &contact, const QList<QList<QPair<QLatin1String, QLatin1String> > > detailList) const
{
    // Default to empty display label. It is up to the client to create a
    // localised presentation of a contact without a name.
    QString displayLabel("");
    
    //loop through the details and create display label
    for(int i = 0; i < detailList.count() && displayLabel.isEmpty(); i++ )
    {
        QList<QPair<QLatin1String, QLatin1String> > detailPairList = detailList.at(i);
        QContactDetail contactDetail;
        
        for(int j = 0; j < detailPairList.count(); j++)
        {
            contactDetail = contact.detail(detailPairList.at(j).first);
                    
            if(displayLabel.isEmpty()){ //read the value and set it as display label
                displayLabel =  contactDetail.value(detailPairList.at(j).second);
            }
            else{ //read the value and append it to the display label
                QString label = contactDetail.value(detailPairList.at(j).second);
                
                if(!label.isEmpty())
                {
                    displayLabel.append(delimiter());
                    displayLabel.append(label);
                }  
            }
        }
    }

    return displayLabel;
}

/*! 
 * delemiter to be used in display label
 * \return delemiter 
 */
QString CntDisplayLabel::delimiter() const
{
    //this will be variated in the future.
    return " ";
}

/*!
 * Returns the details to be used for contact filtering
 */
QList<QPair<QLatin1String, QLatin1String> > CntDisplayLabel::contactFilterDetails() const
{
    return m_contactDisplayLabelDetails.at(0);
}

/*!
 * Returns the details to be used for group filtering
 */
QList<QPair<QLatin1String, QLatin1String> > CntDisplayLabel::groupFilterDetails() const
{
    return m_groupDisplayLabelDetails.at(0);
}
