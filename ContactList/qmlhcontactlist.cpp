#include "qmlhcontactlist.h"

QmlHContactList::QmlHContactList(QObject *parent) : QObject(parent)
{
    m_phoneNumbers << "7021127606" << "9475384723" << "9933802033";
    m_names << "Shahsnak" << "Shekhar" << "Santosh";
}

void QmlHContactList::goTo(QString page)
{
    qDebug() << Q_FUNC_INFO;
    if (page == "contactList")
    {
        emit loadPage("qrc:/ContactList/ContactListView.qml", nullptr);
    }
}

QStringList QmlHContactList::names() const
{
    return m_names;
}

void QmlHContactList::setNames(const QStringList &names)
{
    m_names = names;
}

QStringList QmlHContactList::phoneNumbers() const
{
    return m_phoneNumbers;
}

void QmlHContactList::setPhoneNumbers(const QStringList &phoneNumbers)
{
    m_phoneNumbers = phoneNumbers;
}
