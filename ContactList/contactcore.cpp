#include "contactcore.h"

ContactCore::ContactCore(QObject *parent): WidgetRegistrable (parent)
{

}

void ContactCore::reLoadWidget()
{
    qDebug() << Q_FUNC_INFO;

    qmlRegisterSingletonType<QmlHContactList>("com.crossware.contactListWidget", 1, 0, "QmlHContactList", getQMLHandlerInstance);
    connect(QmlHContactListSingleton::instance(), &QmlHContactList::loadPage, this, &ContactCore::onLoadPage);
    connect(QmlHContactListSingleton::instance(), &QmlHContactList::notifyCore, this, &ContactCore::onNotifyCore);

}

void ContactCore::unLoadWidget()
{

}

void ContactCore::onNotifyCore(QString status)
{
    qDebug() << Q_FUNC_INFO << status;
    emit errorOccured(-1, status);
}

void ContactCore::onLoadPage(QString page, QObject *contex)
{
    qDebug() << Q_FUNC_INFO << page << contex;
    QUrl url = page;
    emit loadPage(url, contex);
}

QObject *ContactCore::getQMLHandlerInstance(QQmlEngine * qmlEngine, QJSEngine * jsEngine)
{
    Q_UNUSED(qmlEngine)
    Q_UNUSED(jsEngine)
    return QmlHContactListSingleton::instance();
}
