#ifndef QMLNAVIGATIONCONTROLLER_H
#define QMLNAVIGATIONCONTROLLER_H

#include <QObject>
#include <QUrl>
#include "singletonprovider.h"

class QmlNavigationController : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QString deviceSplashScreen MEMBER m_spalshScreenSource NOTIFY splashScreenSourceChanged)
    explicit QmlNavigationController(QObject *parent = nullptr);

    Q_INVOKABLE void pageLoaded(QString source);

    QString spalshScreenSource() const;
    void setSpalshScreenSource(const QString &spalshScreenSource);

    QString homeScreen() const;
    void setHomeScreen(const QString &homeScreen);


    QString currScreen() const;

signals:
    void splashScreenSourceChanged();
    void loadScreenSignal(QString sourcePage);
public slots:
    void loadScreen(const QUrl screen);

private:
    QString m_spalshScreenSource;
    QString m_homeScreen;
    QString m_currScreen;
};

typedef singleton<QmlNavigationController> QmlNavigationControllerSingelton;
#endif // QMLNAVIGATIONCONTROLLER_H
