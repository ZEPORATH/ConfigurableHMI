import QtQuick 2.0

Item {
    id: loaderProvider;
    property string currentPage: "";
    signal objectLoaded(string name);

    Loader {
        id: pageLoader;
        anchors.fill: parent;
        objectName: "pageLoader";
        visible: (status == Loader.Ready);

        onStatusChanged: {
            if (status == Loader.Ready) {
                currentPage = pageLoader.source;
            }
            else if (status == Loader.Loading) {
                //Show some animation here
                console.log("Loading...");
            }
            else if (status == Loader.Error) {
                console.log("onStatusChanged error "  + status);
            }
            else {
                console.log("onStatusChanged Inactive");
            }
        }

        onLoaded: {
            objectLoaded(source);
            QmlNavigation.pageLoaded(source);
        }
    }

    Connections {
        target: QmlNavigation;
        onLoadScreenSignal : pageLoader.source = sourcePage;
    }
}
