#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>
#include <QDebug>
#include <memory>

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = nullptr);
    int deviceType();
    QStringList widgetsToLoad();
signals:

public slots:
private:
    QSettings m_settings;
};

#endif // SETTINGS_H
