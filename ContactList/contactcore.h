#ifndef CONTACTCORE_H
#define CONTACTCORE_H

#include <QQmlEngine>
#include "widgetregistrable.h"
#include "qmlhcontactlist.h"

class ContactCore : public WidgetRegistrable
{
public:
    explicit ContactCore(QObject* parent = nullptr);
    virtual void reLoadWidget();
    virtual void unLoadWidget();

private slots:
    void onNotifyCore(QString status);
    void onLoadPage(QString page, QObject* contex = nullptr);
private:
    static QObject* getQMLHandlerInstance(QQmlEngine*qmlEngine, QJSEngine*jsEngine);

};

#endif // CONTACTCORE_H
