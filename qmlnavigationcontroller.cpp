#include "qmlnavigationcontroller.h"

QmlNavigationController::QmlNavigationController(QObject *parent) : QObject(parent)
{

}

void QmlNavigationController::pageLoaded(QString source)
{
    qDebug() << Q_FUNC_INFO << source;
}

void QmlNavigationController::goBack()
{
    qDebug() << Q_FUNC_INFO;
    printNavSequence();
    auto index = m_navSequence.indexOf(m_currScreen);
    if (index-1 > 0)
    {
        m_currScreen = m_navSequence[index-1];
        if (m_currScreen == m_homeScreen)
        {
           m_navSequence.clear();
           this->loadScreen(m_currScreen);
        }
        else
        {
            emit loadScreenSignal(m_currScreen);
        }
    }
    else
    {
        m_navSequence.clear();
        this->loadScreen(m_homeScreen);
    }
}

void QmlNavigationController::goForward()
{
    qDebug() << Q_FUNC_INFO;
    printNavSequence();
    auto index =  m_navSequence.indexOf(m_currScreen);
    if (index < m_navSequence.size()-2)
    {
        m_currScreen = m_navSequence[index+1];
        emit loadScreenSignal(m_currScreen);
    }
}

void QmlNavigationController::goHome()
{
    qDebug() << Q_FUNC_INFO;
    printNavSequence();
    m_navSequence.clear();
    m_currScreen = m_homeScreen;
    this->loadScreen(m_currScreen);
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
    qDebug() << Q_FUNC_INFO;
    m_homeScreen = homeScreen;
    m_navSequence.push_back(m_homeScreen);
}

void QmlNavigationController::loadScreen(const QUrl screen)
{
    /**
      Do some storing of previous page sequence so to make back navigation. Take navigation as navObjects of
      url & context objects.
      */
    m_navSequence.push_back(screen.toString());
    m_currScreen = screen.toString();
    emit loadScreenSignal(m_currScreen);
}

void QmlNavigationController::printNavSequence()
{
    qDebug() << Q_FUNC_INFO << m_navSequence;
}

QString QmlNavigationController::currScreen() const
{
    return m_currScreen;
}
