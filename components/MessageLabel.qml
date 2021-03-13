import QtQuick 2.0

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
