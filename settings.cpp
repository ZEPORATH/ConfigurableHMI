#include "settings.h"

const QString deviceType_Key = "Settings/devicetype";
const QString widgets_Key    = "Settings/widgets";

Settings::Settings(QObject *parent) : QObject(parent)
{
    m_settings.setPath(QSettings::IniFormat, QSettings::UserScope, ":/resources/settings.ini");
//    m_settings.setValue(deviceType_Key, QVariant::fromValue(1));
//    QStringList widgets  = {"caller", "contactList", "Clock"}; //, "Weather"};
//    m_settings.setValue(widgets_Key, QVariant::fromValue(widgets));
}

int Settings::deviceType()
{
    qDebug() << Q_FUNC_INFO;
    return m_settings.value(deviceType_Key).toInt();
}

QStringList Settings::widgetsToLoad()
{
    qDebug() << Q_FUNC_INFO;
    return m_settings.value(widgets_Key).toStringList();
}

