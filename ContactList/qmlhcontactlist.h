#ifndef QMLHCONTACTLIST_H
#define QMLHCONTACTLIST_H

#include <QObject>
#include <QDebug>
#include "singletonprovider.h"

class QmlHContactList : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QStringList names READ names WRITE setNames NOTIFY namesChanged)
    Q_PROPERTY(QStringList phoneNumbers MEMBER m_phoneNumbers)

    explicit QmlHContactList(QObject *parent = nullptr);
    Q_INVOKABLE void goTo(QString page);
    QStringList names() const;
    void setNames(const QStringList &names);

    QStringList phoneNumbers() const;
    void setPhoneNumbers(const QStringList &phoneNumbers);

signals:
    void loadPage(QString url, QObject* contextObj);
    void notifyCore(QString status);
    void namesChanged();
    void phoneNumbersChanged();

public slots:
private:
    QStringList m_names;
    QStringList m_phoneNumbers;
};
typedef singleton<QmlHContactList> QmlHContactListSingleton;
#endif // QMLHCONTACTLIST_H
