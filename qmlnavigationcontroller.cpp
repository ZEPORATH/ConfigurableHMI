#include "qmlnavigationcontroller.h"

QmlNavigationController::QmlNavigationController(QObject *parent) : QObject(parent)
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
    m_currScreen = screen.toString();
}

QString QmlNavigationController::currScreen() const
{
    return m_currScreen;
}
