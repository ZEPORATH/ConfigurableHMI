import QtQuick 2.0

Rectangle {
    id: weatherWidget;
    objectName: "weatherWidget";

    width: parent.width * 0.10;
    height: parent.height * 0.10;
    color: "purple";
    Image {
        id: weatherIcon
        source: "qrc:/resources/weather.png"
        anchors.fill: parent;
    }
    Text {
        id: weatherTemp
        text: "33";
        color: "white";
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.bottom: parent.bottom;
    }
}

