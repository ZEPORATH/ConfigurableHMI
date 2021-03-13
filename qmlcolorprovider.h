#ifndef QMLCOLORPROVIDER_H
#define QMLCOLORPROVIDER_H

#include <QObject>
#include <QColor>
#include "singletonprovider.h"

class QmlColorProvider : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QColor bgColor MEMBER m_bgColor NOTIFY bgColorChanged)
    explicit QmlColorProvider(QObject *parent = nullptr);

    QColor bgColor() const;
    void setBgColor(const QColor &bgColor);

    Q_INVOKABLE QString getIconPath(QString iconName);

signals:
    void bgColorChanged();
public slots:
private:
    QColor m_bgColor;
};
typedef singleton<QmlColorProvider> QmlColorProviderSingleton;
#endif // QMLCOLORPROVIDER_H
