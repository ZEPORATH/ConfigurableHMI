#include "qmlmessagenotifier.h"

QmlMessageNotifier::QmlMessageNotifier(QObject *parent) : QObject(parent)
{

}

void QmlMessageNotifier::setProgressMessage(const QString &progressMessage)
{
    qDebug() << Q_FUNC_INFO;
    m_progressMessage = progressMessage;
    emit loadProgressMessage(m_progressMessage);
}
