#include "callercore.h"

CallerCore::CallerCore(QObject *parent): WidgetRegistrable(parent)
{
}

void CallerCore::reLoadWidget()
{
    qmlRegisterSingletonType<QmlHCaller>("com.crossware.callerWidget", 1, 0, "QmlHCaller", getQMLHandlerInstance);

    connect(QmlHCallerSingleton::instance(), &QmlHCaller::notifyCore, this, &CallerCore::onNotifyCore);
}

void CallerCore::unLoadWidget()
{

}

void CallerCore::onNotifyCore(QString status)
{
    qDebug() << Q_FUNC_INFO << status;
    emit errorOccured(-1, status);
}

QObject *CallerCore::getQMLHandlerInstance(QQmlEngine *, QJSEngine *)
{

    return QmlHCallerSingleton::instance();
}

