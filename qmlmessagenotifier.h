#ifndef QMLMESSAGENOTIFIER_H
#define QMLMESSAGENOTIFIER_H

#include <QObject>
#include <QDebug>
#include "singletonprovider.h"
class QmlMessageNotifier : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QString progressMessage MEMBER m_progressMessage NOTIFY loadProgressMessage)
    explicit QmlMessageNotifier(QObject *parent = nullptr);


signals:
    void loadProgressMessage(QString message);
public slots:
    void setProgressMessage(const QString &progressMessage);

private:
    QString m_progressMessage;
};
typedef singleton<QmlMessageNotifier> QmlMessageNotifierSingleton;
#endif // QMLMESSAGENOTIFIER_H
