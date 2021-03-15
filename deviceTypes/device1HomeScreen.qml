import QtQuick 2.0
import "../CallerModule"
import "../TimeModule"
import "../WeatherModule"
import "../components"
Rectangle {
    id: device1HomeScreen;
    objectName: "device1HomeScreen";
    visible: true;
    width: 640;
    height: 480;
    color: QmlColorProvider.bgColor;
    property string currentPage: "device1HomeScreen.qml";

    signal objectLoaded(string name);

    Component.onCompleted: {
        console.log("Loaded ", objectName);
    }

   CallerModule {

   }

   TimeWidget {

   }

   WeatherWidget {

   }

   LoaderProvider{
       anchors.fill: parent;
       currentPage: "device1HomeScreen.qml"
   }
}
