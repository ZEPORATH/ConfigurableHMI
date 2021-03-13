#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "qmlenginecontroller.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    app.instance()->setApplicationName("ConfiguratbleHMI");
    app.instance()->setOrganizationName("Zenitel");
    app.instance()->setApplicationVersion("1.0.0");
    app.instance()->setObjectName("MainThread");
    QSharedPointer<QmlEngineController> qmlEngine = QSharedPointer<QmlEngineController>(new QmlEngineController);


    return app.exec();
}
