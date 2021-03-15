import QtQuick 2.0

Rectangle {
    id: contactWidget;
    objectName: "ContactWidget";

    width: parent.width * 0.10;
    height: parent.height * 0.10;
    color: "gold"

    Image {
        id: contactListIcon
        source: "qrc:/resources/contactList.webp";
        width: parent.width * 0.90;
        height: parent.height * 0.90;
    }
    Text {
        text: qsTr("Contacts");
        anchors.top: contactListIcon.bottom;
        anchors.horizontalCenter: parent.horizontalCenter;
        color: "white"
    }
    MouseArea {
        anchors.fill: parent;
        onClicked: {
            console.log("Caller Contact List");
        }
    }
}
