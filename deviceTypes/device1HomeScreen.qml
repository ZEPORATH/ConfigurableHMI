import QtQuick 2.0
import "../CallerModule"
import "../TimeModule"
import "../WeatherModule"
Rectangle {
    id: device1HomeScreen;
    objectName: "device1HomeScreen";
    visible: true;
    width: 640;
    height: 480;
    color: QmlColorProvider.bgColor;

    Component.onCompleted: {
        console.log("Loaded ", objectName);
    }

   CallerModule {

   }

   TimeWidget {

   }

   WeatherWidget {

   }
}
