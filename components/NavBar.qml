import QtQuick 2.0

Item {
    property int dims: 40;
    height: dims+10;
    width: iconsRow.width;

    Row{
        id: iconsRow;
        anchors.fill: parent;
        spacing: 12;

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
                onClicked: {
                    QmlNavigation.goBack();
                    console.log("backbuttonClicked");
                }
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
                onClicked: {
                    QmlNavigation.goHome();
                    console.log("homeButtonClicked");
                }
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
                onClicked: {
                    QmlNavigation.goForward();
                    console.log("forwardButtonClicked");
                }
            }
        }
    }
}
