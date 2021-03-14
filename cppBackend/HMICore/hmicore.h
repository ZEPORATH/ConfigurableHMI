#ifndef HMICORE_H
#define HMICORE_H

#include <QObject>
#include <QQuickView>
#include "qmlnavigationcontroller.h"
#include "settings.h"
#include "widgetregistrable.h"
#include "CallerModule/callercore.h"

class HMICore : public QObject
{
    Q_OBJECT
public:
    explicit HMICore(QObject *parent = nullptr);
    void initialize();
signals:
    void bootComplete();
    void errorOccured(int errCode, QString errorString);
    void addContext(QObject* contextObj);
public slots:
    void onLoadComplete();
    void onErrorOccured(int errCode, QString errorString);
    void onLoadPage(QUrl pageUrl, QObject* contextObject=nullptr); //Send pageNavigation to navigation Manager with contextObject in case u want to expose some context
};

#endif // HMICORE_H
