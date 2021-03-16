import QtQuick 2.0
import com.crossware.contactListWidget 1.0 as QmlHContactListSingleton

Item {
    id: contactList;
    objectName: "contactList";
    x: 80
    y: 60
    Component.onCompleted:
    {
        contactModel.clear();
        var names = QmlHContactListSingleton.QmlHContactList.names;
        var phoneNumbers = QmlHContactListSingleton.QmlHContactList.phoneNumbers;

        for (var i=0; i< names.length; i++)
        {
            contactModel.append({"name": names[i], "number": phoneNumbers[i]});
        }
    }

    Component {
            id: contactDelegate
            Item {
                width: 180; height: 40
                Column {
                    Text { text: '<b>Name:</b> ' + name }
                    Text { text: '<b>Number:</b> ' + number }
                }
            }
        }

        ListView {
            anchors.fill: parent
            model: contactModel //TODO supply a model data here
            delegate: contactDelegate
            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            focus: true
        }

        ListModel {
            id: contactModel

        }
}
