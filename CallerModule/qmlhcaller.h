#ifndef QMLHCALLER_H
#define QMLHCALLER_H

#include <QObject>

class QmlHCaller : public QObject
{
    Q_OBJECT
public:
    explicit QmlHCaller(QObject *parent = nullptr);

signals:

public slots:
};

#endif // QMLHCALLER_H
