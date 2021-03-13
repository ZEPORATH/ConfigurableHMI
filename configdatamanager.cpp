#include "configdatamanager.h"

ConfigDataManager::ConfigDataManager(QObject *parent) : QObject(parent)
{
    m_configFPath = ":/resources/config.json";
}
