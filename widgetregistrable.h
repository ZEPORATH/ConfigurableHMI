#ifndef WIDGETREGISTRABLE_H
#define WIDGETREGISTRABLE_H
#include <QObject>
#include <QUrl>
#include <QtDebug>

/**
 * Only behaviour required is to send fewSignals and expose capability of loading and unloading
 * */
class WidgetRegistrable: public QObject {
//    ~WidgetRegistrable() {qDebug() << Q_FUNC_INFO;}
public:
    explicit WidgetRegistrable(QObject* parent = nullptr): QObject(parent){}
signals:
    void loadPage(QUrl pageUrl, QObject* contextObject=nullptr); //Send pageNavigation to navigation Manager with contextObject in case u want to expose some context
    void errorOccured(int errCode, QString err);
    void loadComplete();
public slots:
    virtual void reLoadWidget() = 0;
    virtual void unLoadWidget() = 0;
private:
    Q_OBJECT
};

#endif // WIDGETREGISTRABLE_H
