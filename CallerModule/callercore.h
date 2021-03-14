#ifndef CALLERCORE_H
#define CALLERCORE_H

#include <QObject>
#include <QDebug>
#include <QQmlEngine>
#include "widgetregistrable.h"
#include "qmlhcaller.h"

class CallerCore : public WidgetRegistrable
{
public:
    explicit CallerCore(QObject* parent = nullptr);
    virtual void reLoadWidget();
    virtual void unLoadWidget();
private slots:
    void onNotifyCore(QString status);

private:
    static QObject* getQMLHandlerInstance(QQmlEngine*, QJSEngine*);
};
#endif // CALLERCORE_H
