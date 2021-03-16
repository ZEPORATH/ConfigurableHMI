import QtQuick 2.0
import "../CallerModule"
import "../ContactList"
import "../WeatherModule"
import "../TimeModule"
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
    NavBar {
        id: navBar;
        anchors.bottom: parent.bottom
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottomMargin: 40
        anchors.top: parent.top
        anchors.topMargin: 10

    }

    Column {
        id: widgetColumns;
        anchors.top: navBar.bottom;
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.topMargin: -376

        spacing: 15;


        CallerModule {
            anchors.horizontalCenter: parent.horizontalCenter;
        }

        ContactWidget {
            anchors.horizontalCenter: parent.horizontalCenter;
        }

        WeatherWidget {

        }

        TimeWidget {

        }
    }

    LoaderProvider{
        anchors.fill: parent;
        currentPage: "device1HomeScreen.qml"
    }
}
