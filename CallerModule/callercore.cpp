#include "callercore.h"

CallerCore::CallerCore(QObject *parent): WidgetRegistrable(parent)
{

}

void CallerCore::reLoadWidget()
{
    qmlRegisterType<QmlHCaller>("com.crossware.callerWidget", 1, 0, "QmlHCaller");
}

void CallerCore::unLoadWidget()
{

}
