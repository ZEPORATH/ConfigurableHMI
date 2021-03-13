#include "qmlcolorprovider.h"

QmlColorProvider::QmlColorProvider(QObject *parent) : QObject(parent)
{

}

QColor QmlColorProvider::bgColor() const
{
    return m_bgColor;
}

void QmlColorProvider::setBgColor(const QColor &bgColor)
{
    m_bgColor = bgColor;
}

QString QmlColorProvider::getIconPath(QString iconName)
{
    return QString("qrc:/resources/LoaderIcon.png");
}
