#ifndef QMLHCALLER_H
#define QMLHCALLER_H

#include <QObject>
#include <QtDebug>
#include "singletonprovider.h"
class QmlHCaller : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(bool mouseClicked MEMBER m_mouseClicked NOTIFY mouseClicked)
    Q_PROPERTY(int numPressed MEMBER m_numPressed NOTIFY numPressed )
    explicit QmlHCaller(QObject *parent = nullptr);

    void setMouseClicked(bool mouseClicked);

    Q_INVOKABLE void setNumPressed(int numPressed);
    Q_INVOKABLE void goTo(QString page);
signals:
    void mouseClicked();
    void numPressed(int num);
    void notifyCore(QString status);
    void loadPage(QString url, QObject* contextObj);
public slots:
private:
    bool m_mouseClicked;
    int m_numPressed;
};
typedef singleton<QmlHCaller> QmlHCallerSingleton;
#endif // QMLHCALLER_H
