#ifndef CALLERCORE_H
#define CALLERCORE_H

#include <QObject>
#include <QQmlEngine>
#include "widgetregistrable.h"
#include "qmlhcaller.h"

class CallerCore : public WidgetRegistrable
{
public:
    explicit CallerCore(QObject* parent = nullptr);
    virtual void reLoadWidget();
    virtual void unLoadWidget();
};

#endif // CALLERCORE_H
