#include "qmlenginecontroller.h"

QmlEngineController::QmlEngineController(QObject *parent) : QObject(parent)
{
    m_loaderView = nullptr;
    m_mainView = nullptr;
    m_contextObjects.clear();

    Settings settings;
    showSplashScreen(settings.deviceType());
    QmlMessageNotifierSingleton::instance()->setProgressMessage("Loading backend logic. Please wait...");

    startHMICore();

}

void QmlEngineController::startHMICore()
{
    qDebug() << Q_FUNC_INFO;
    //TODO: remove this code, just for testing
    //--start
    m_timer = new QTimer();
    m_timer->setSingleShot(true);
    m_timer->setInterval(1000);
    connect(m_timer, &QTimer::timeout, [=](){
        QmlMessageNotifierSingleton::instance()->setProgressMessage("Loading Complete... WELCOME!");
        m_timer->stop();
        m_timer->deleteLater();
    });
    m_timer->start();
    //--- end

    QSharedPointer<HMICore> hmiCore = QSharedPointer<HMICore>::create();
    if (!hmiCore.isNull())
    {
        connect(hmiCore.get(), &HMICore::bootComplete, this, &QmlEngineController::showMainScreen);
        connect(hmiCore.get(), &HMICore::errorOccured, this, &QmlEngineController::handleError);
        connect(hmiCore.get(), &HMICore::addContext, this, [=](QObject* contextObj){this->m_contextObjects.append(contextObj);});
    }
    else
    {
        qDebug() << Q_FUNC_INFO << "Error creating HMI core";
    }
    hmiCore->initialize();
}

void QmlEngineController::showMainScreen()
{
    qDebug() << Q_FUNC_INFO;
    m_loaderView->close();

    m_mainView =  QSharedPointer<QQuickView>::create();
    m_mainView->rootContext()->setContextProperty("QmlNavigation", QmlNavigationControllerSingelton::instance()) ;
    m_mainView->rootContext()->setContextProperty(QmlColorProviderSingleton::instance()->metaObject()->className(), QmlColorProviderSingleton::instance()) ;
    m_mainView->rootContext()->setContextProperty("QmlMessageNotifier", QmlMessageNotifierSingleton::instance());
    Q_FOREACH(auto obj, m_contextObjects)
    {
        m_mainView->rootContext()->setContextProperty(obj->metaObject()->className(), obj);
    }
    m_mainView->setSource(QUrl(QmlNavigationControllerSingelton::instance()->homeScreen()));
    m_mainView->show();
    m_loaderView->destroy();
}

void QmlEngineController::handleError(int errCode, QString error)
{
    qDebug() << Q_FUNC_INFO;
}

void QmlEngineController::showSplashScreen(int type)
{
    QString splashScreen;
    QColor bgColor;
    switch (type)
    {
    case 1:
        splashScreen = "qrc:/deviceTypes/device1splashLoader.qml";
        bgColor = "skyblue";
        break;
    case 2:
        splashScreen = "qrc:/deviceTypes/device2splashLoader.qml";
        bgColor = "green";
        break;
    case 3:
        splashScreen = "qrc:/deviceTypes/device2splashLoader.qml";
        bgColor = "blue";
        break;
    }
    QmlColorProviderSingleton::instance()->setBgColor(bgColor);
    QmlNavigationControllerSingelton::instance()->setSpalshScreenSource(splashScreen);

    m_loaderView = QSharedPointer<QQuickView>::create();
    m_loaderView->rootContext()->setContextProperty("QmlNavigation", QmlNavigationControllerSingelton::instance()) ;
    m_loaderView->rootContext()->setContextProperty("QmlColorProvider", QmlColorProviderSingleton::instance()) ;
    m_loaderView->rootContext()->setContextProperty("QmlMessageNotifier", QmlMessageNotifierSingleton::instance());

    m_loaderView->setSource(QUrl("qrc:/splashLoader.qml"));
    m_loaderView->show();
}
