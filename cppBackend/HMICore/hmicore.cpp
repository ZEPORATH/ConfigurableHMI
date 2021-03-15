#include "hmicore.h"

HMICore::HMICore(QObject *parent) : QObject(parent)
{
    //Do RAII here
}

void HMICore::initialize()
{
    Settings s;
    QString homeScreen = QString("qrc:/deviceTypes/device%1HomeScreen.qml").arg(s.deviceType());
    auto widgetList = s.widgetsToLoad();
    QList<WidgetRegistrable*> widgets;

    Q_FOREACH(auto widgetName, widgetList)
    {
        WidgetRegistrable* widgetReg {nullptr};

        if (widgetName.toLower() == "caller")
        {
            widgetReg = new CallerCore();
        }
        //Add extra if else checks for other registrable widgets

        //Make necessary connections
        if (widgetReg)
        {
            connect(widgetReg, &WidgetRegistrable::loadPage, this, &HMICore::onLoadPage);
            connect(widgetReg, &WidgetRegistrable::loadComplete, this, &HMICore::onLoadComplete);
            connect(widgetReg, &WidgetRegistrable::errorOccured, this, &HMICore::onErrorOccured);

            widgetReg->reLoadWidget(); //Load the widget in the memory
        }
        else
        {
            //Factory doesn't know the type. Unable to create
            qDebug() << Q_FUNC_INFO << " Factory doesn't know the type. Unable to create " << widgetName;
        }
    }

    QmlNavigationControllerSingelton::instance()->setHomeScreen(homeScreen);
//    emit bootComplete();
}

void HMICore::onLoadComplete()
{

}

void HMICore::onErrorOccured(int errCode, QString errorString)
{
    qDebug() << Q_FUNC_INFO << errCode << errorString;

}

void HMICore::onLoadPage(QUrl pageUrl, QObject *contextObject)
{
    qDebug() << Q_FUNC_INFO << endl;
    if (contextObject)
    {
        emit addContext(contextObject);
    }
    QmlNavigationControllerSingelton::instance()->loadScreen(pageUrl);
}
