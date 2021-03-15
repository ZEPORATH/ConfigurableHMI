import QtQuick 2.0

Rectangle {
    id:timeDisplay;
    objectName: "TimeDisplay"

    width: parent.width * 0.40;
    height: parent.height * 0.10;
    color: "white";

    Row {
        anchors.fill: parent;
        spacing: 10;
        anchors.margins: 20;
        Text {
            id: hour
            text: qsTr("12")
            color: "black";
            font.pixelSize: 12;
            anchors.verticalCenter: parent.verticalCenter;
        }
        Text {
            text: qsTr(":")
            color: "green";
            font.pixelSize: 12;
            anchors.verticalCenter: parent.verticalCenter;
        }
        Text {
            id: minutes
            text: qsTr("10")
            color: "gray";
            font.pixelSize: 12;
            anchors.verticalCenter: parent.verticalCenter;
        }
        Text {
            text: qsTr(":")
            color: "blue";
            font.pixelSize: 12;
            anchors.verticalCenter: parent.verticalCenter;
        }
        Text {
            id: seconds
            text: qsTr("58");
            color: "lightgray";
            font.pixelSize: 12;
            anchors.verticalCenter: parent.verticalCenter;
        }
    }
}
