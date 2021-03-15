#include "callercore.h"

CallerCore::CallerCore(QObject *parent): WidgetRegistrable(parent)
{
}

void CallerCore::reLoadWidget()
{
    qDebug() << Q_FUNC_INFO;

    qmlRegisterSingletonType<QmlHCaller>("com.crossware.callerWidget", 1, 0, "QmlHCaller", getQMLHandlerInstance);
    connect(QmlHCallerSingleton::instance(), &QmlHCaller::notifyCore, this, &CallerCore::onNotifyCore);
    connect(QmlHCallerSingleton::instance(), &QmlHCaller::loadPage, this, &CallerCore::onLoadPage);
}

void CallerCore::unLoadWidget()
{

}

void CallerCore::onNotifyCore(QString status)
{
    qDebug() << Q_FUNC_INFO << status;
    emit errorOccured(-1, status);
}

void CallerCore::onLoadPage(QString page, QObject *contex)
{
    qDebug() << Q_FUNC_INFO << page << contex;
    QUrl url = page;
    emit loadPage(url, contex);
}

QObject *CallerCore::getQMLHandlerInstance(QQmlEngine *, QJSEngine *)
{
    return QmlHCallerSingleton::instance();
}

