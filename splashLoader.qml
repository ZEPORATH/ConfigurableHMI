import QtQuick 2.0

Rectangle {
    id: splashLoader;
    objectName: "splashLoader";
    visible: true;
    width: 640;
    height: 480;
    color: QmlColorProvider.bgColor;

    Loader
    {
        id:pageLoader;
        asynchronous: true;
        anchors.fill: parent;
        visible: (status == Loader.Ready)
        source: QmlNavigation.deviceSplashScreen;

        onStatusChanged: {
            if (status == Loader.Ready)
            {
                console.log("Page Loaded: ", source);
            }
            else if (status == Loader.Loading)
            {
                console.log("Loading page: ", source);
            }
            else if (status == Loader.Error)
            {
                console.log("Error Loading: ", status);
            }
            else {
                console.log("Loader inactive or IDK", status);
            }

        }
    }


}
