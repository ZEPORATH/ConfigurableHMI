import QtQuick 2.0
import com.crossware.callerWidget 1.0 as QmlHCallerSingleton
//Make a phone Icon clickable here, clicking on which takes to a dialpad screen.

Item {
    id: callerDisplay;
    objectName: "CallerModule";
    anchors.fill: parent;
    Rectangle {
        anchors.centerIn: parent;
        width: parent.width*0.10;
        height: parent.height*0.10;
        color: "red";
        Text {
            text: qsTr("Phone")
            anchors.centerIn: parent;
            color: "white"
        }

        MouseArea {
            anchors.fill: parent;
            onClicked: {
                QmlHCallerSingleton.QmlHCaller.goTo("dialpad");
            }
        }
    }
}
