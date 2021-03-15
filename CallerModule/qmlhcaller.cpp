#include "qmlhcaller.h"

QmlHCaller::QmlHCaller(QObject *parent) : QObject(parent)
{

}

void QmlHCaller::setMouseClicked(bool mouseClicked)
{
    qDebug() << Q_FUNC_INFO;
    m_mouseClicked = mouseClicked;

}

void QmlHCaller::setNumPressed(int numPressed)
{
    m_numPressed = numPressed;
    emit this->numPressed(numPressed);
    emit notifyCore(QString("m good") + Q_FUNC_INFO);
}

void QmlHCaller::goTo(QString page)
{
    qDebug() << Q_FUNC_INFO << endl;
    if (page == "dialpad")
    {
        emit loadPage("qrc:/CallerModule/dialpad.qml", nullptr);
    }
}

