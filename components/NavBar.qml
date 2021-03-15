import QtQuick 2.0

Item {
    property int dims: 40;
    height: dims+10;
    anchors.left: parent.left;
    anchors.right: parent.right;
    Row{
        anchors.fill: parent;
        Rectangle {
            id: backIconArea;
            width: dims;
            height: dims;
            Image {
                id: backIcon
                source: "qrc:/resources/backward-arrow.png"
                anchors.fill: parent;
            }
            MouseArea {
                anchors.fill: parent;
            }
        }
        Rectangle {
            id: homeIconArea;
            width: dims;
            height: dims;
            Image {
                id: homeIcon
                source: "qrc:/resources/home.png"
                anchors.fill: parent
            }
            MouseArea {
                anchors.fill: parent;
            }
        }
        Rectangle {
            id: forwardIconArea;
            width: dims;
            height: dims;
            Image {
                id: forwardIcon
                source: "qrc:/resources/right-arrow.png"
                anchors.fill: parent
            }
            MouseArea {
                anchors.fill: parent;
            }
        }
    }
}
