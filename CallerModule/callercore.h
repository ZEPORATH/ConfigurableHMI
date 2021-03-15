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
//    ~CallerCore() {qDebug() << Q_FUNC_INFO;}
    virtual void reLoadWidget();
    virtual void unLoadWidget();
signals:
private slots:
    void onNotifyCore(QString status);
    void onLoadPage(QString page, QObject* contex = nullptr);
private:
    static QObject* getQMLHandlerInstance(QQmlEngine*, QJSEngine*);
};
#endif // CALLERCORE_H
