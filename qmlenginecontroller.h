#ifndef QMLENGINECONTROLLER_H
#define QMLENGINECONTROLLER_H

#include <QObject>
#include <QQuickView>
#include <QQmlContext>
#include <QTimer>
#include "settings.h"
#include "qmlcolorprovider.h"
#include "qmlnavigationcontroller.h"
#include "qmlmessagenotifier.h"
#include "cppBackend/HMICore/hmicore.h"
class QmlEngineController : public QObject
{
    Q_OBJECT
public:
    explicit QmlEngineController(QObject *parent = nullptr);

    void startHMICore();
    void showMainScreen();
signals:

public slots:
    void handleError(int errCode, QString error);
private:
    void showSplashScreen(int type);
private:
    QSharedPointer<QQuickView> m_loaderView;
    QSharedPointer<QQuickView> m_mainView;
    QList<QObject*> m_contextObjects;
    QTimer* m_timer;
};

#endif // QMLENGINECONTROLLER_H
