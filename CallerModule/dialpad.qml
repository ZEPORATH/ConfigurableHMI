import QtQuick 2.12
import "../components"
Item {
    width: childrenRect.width
    height: childrenRect.height
    property string dialString
    signal dial(string numberToDial)
    signal hangup

    Rectangle {
        id: dialNumber
        height: dialText.height + 5
        width: numberPad.width
        anchors.top: parent.top
        anchors.left: parent.left
        color: "white"
        radius: 5
        border.width: 3
        border.color: "black"

        Text {
            id: dialText
            text: dialString
            anchors.centerIn: parent
        }
    }

    Grid {
        id: numberPad
        width: childrenRect.width
        height: childrenRect.height
        anchors.top: dialNumber.bottom
        anchors.left: parent.left
        anchors.topMargin: 5
        columns: 3
        spacing: 5

        DialButton { buttonText: "1"; onClicked: { dialString += "1";} }
        DialButton { buttonText: "2"; onClicked: { dialString += "2";} }
        DialButton { buttonText: "3"; onClicked: { dialString += "3";} }
        DialButton { buttonText: "4"; onClicked: { dialString += "4";} }
        DialButton { buttonText: "5"; onClicked: { dialString += "5";} }
        DialButton { buttonText: "6"; onClicked: { dialString += "6";} }
        DialButton { buttonText: "7"; onClicked: { dialString += "7";} }
        DialButton { buttonText: "8"; onClicked: { dialString += "8";} }
        DialButton { buttonText: "9"; onClicked: { dialString += "9";} }
        DialButton { buttonText: "*"; onClicked: { dialString += "*";} }
        DialButton { buttonText: "0"; onClicked: { dialString += "0";} }
        DialButton { buttonText: "#"; onClicked: { dialString += "#";} }
    }

    DialButton {
        id: hangUpButton
        height: { (numberPad.height / 2) - 2 }
        width: 50
        anchors.top: numberPad.top
        anchors.left: numberPad.right
        anchors.leftMargin: 5
        hoverColor: "red"
        color: "crimson"
        onClicked: {
            dialString = ""
            hangup()
        }
        Image {
            anchors.centerIn: parent
            source: "qrc:/resources/hangup.webp"
            transformOrigin: "Center"
            height: parent.width;
            width: parent.width;

        }
    }

    DialButton {
        id: callButton
        width: 50
        height: {(numberPad.height/2) -2}
        anchors.top: hangUpButton.bottom
        anchors.left: numberPad.right
        anchors.leftMargin: 5
        anchors.topMargin: 4
        color: "mediumseagreen"
        hoverColor: "lightgreen"
        onClicked: {
            if (dialString != "") {
                dial(dialString)
                dialString = ""
            }
        }

        Image {
            anchors.centerIn: parent
            source: "qrc:/resources/phoneRing.png"
            transformOrigin: "Center"
            height: parent.width;
            width: parent.width;
        }
    }
}
