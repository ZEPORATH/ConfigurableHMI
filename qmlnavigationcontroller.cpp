#include "qmlnavigationcontroller.h"

QmlNavigationController::QmlNavigationController(QObject *parent) : QObject(parent)
{

}

void QmlNavigationController::pageLoaded(QString source)
{

}

QString QmlNavigationController::spalshScreenSource() const
{
    return m_spalshScreenSource;
}

void QmlNavigationController::setSpalshScreenSource(const QString &spalshScreenSource)
{
    m_spalshScreenSource = spalshScreenSource;
}

QString QmlNavigationController::homeScreen() const
{
    return m_homeScreen;
}

void QmlNavigationController::setHomeScreen(const QString &homeScreen)
{
    m_homeScreen = homeScreen;
}

void QmlNavigationController::loadScreen(const QUrl screen)
{
    /**
      Do some storing of previous page sequence so to make back navigation. Take navigation as navObjects of
      url & context objects.
      */
    m_currScreen = screen.toString();
    emit loadScreenSignal(m_currScreen);
}

QString QmlNavigationController::currScreen() const
{
    return m_currScreen;
}
