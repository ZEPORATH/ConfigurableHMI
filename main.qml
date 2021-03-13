import QtQuick 2.12
import QtQuick.Window 2.12
import "components"

//this is the fallback window, if core is unable to comeUp

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle {
        anchors.fill: parent;
        color: QmlColorProvider.bgColor;
        Image{
            id: companyLogo
            width: parent.width*0.4;
            height: parent.height*0.4;
        }
        MessageLabel{}
    }
}
