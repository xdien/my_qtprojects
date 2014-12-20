import QtQuick 2.0
import QtQuick.Dialogs 1.0
import QtQuick.Window 2.1
import Qt.labs.folderlistmodel 1.0
import QtSensors 5.3



Window {
    property  variant myPoint: null
    id: root
    visible: true
    width: 640; height: 320
    color: "black"
    property int highestZ: 0
    property real defaultSize: 200
    Flickable {
        id: flickable1
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        flickableDirection: Flickable.HorizontalFlick
        Item {
            id: test
            Image {
                id: image1
                x: 137
                y: 120
                width: 100
                height: 100
                source: "qrc:/../Google Chrome Icons/binary_field_icon.jpg"
        }

        }

        Item {
            function readValues(anArray, anObject) {
                for (var i=0; i<anArray.length; i++)
                    console.log("Array item:", anArray[i])

                for (var prop in anObject) {
                    console.log("Object item:", prop, "=", anObject[prop])
                }
            }
        }
        Item {
            id: c
            Image {
                id: image2
                x: 420
                y: 101
                width: 100
                height: 100
                source: "qrc:/../Google Chrome Icons/binary_field_icon.jpg"

                MouseArea {
                    id: mouseArea1
                    anchors.rightMargin: 0
                    anchors.bottomMargin: 0
                    anchors.leftMargin: 0
                    anchors.topMargin: 0
                    anchors.fill: parent
                    onClicked:
                    {
                        myPoint = mapFromItem(image1,mouseX,mouseY)
                        readValues()

                    }
                }
            }
        }

    }

}
