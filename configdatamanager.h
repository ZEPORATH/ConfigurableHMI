#ifndef CONFIGDATAMANAGER_H
#define CONFIGDATAMANAGER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>

class ConfigDataManager : public QObject
{
    Q_OBJECT
public:
    explicit ConfigDataManager(QObject *parent = nullptr);

signals:

public slots:
private:
    QString m_configFPath;
};

#endif // CONFIGDATAMANAGER_H
