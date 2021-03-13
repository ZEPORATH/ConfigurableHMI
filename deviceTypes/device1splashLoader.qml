import QtQuick 2.0

Item {
    id: device1splashLoader;
    objectName: "device1SplashLoader";
    anchors.fill: parent;
    property alias loadingText: loadingText.text;



    Image {
        id: loaderIcon
        source: QmlColorProvider.getIconPath("loader");
        scale: 1.5;
        anchors.centerIn: parent;
    }

    Text {
        id: loadingText
        color: "white"
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: loaderIcon.bottom
        anchors.topMargin: 50
        font.family: "hnc"
        font.pixelSize: 26
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WordWrap
        text: QmlMessageNotifier.progressMessage
    }

    Component.onCompleted: animation.start();
    Component.onDestruction: animation.stop();
    SequentialAnimation {
        id : animation
        loops: Animation.Infinite
        running: true
        PropertyAnimation {
            target: loaderIcon
            property: "rotation"
            from: 430
            to: 70
            duration: 1000
        }
    }
}

