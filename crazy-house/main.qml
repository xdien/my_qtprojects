import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.2

Window {
    id: window1
    visible: true
    width: 400
    height: 800
        Button {
            id: button1
            x: 292
            y: 129
            text: qsTr("Connect")
        }

        TextField {
            id: textField1
            x: 220
            y: 17
            inputMask: qsTr("")
            placeholderText: "Text Field"
        }

        TextField {
            id: textField2
            y: 66
            anchors.left: parent.left
            anchors.leftMargin: 220
            placeholderText: qsTr("Text Field")
        }

        Label {
            id: label1
            x: 8
            y: 21
            text: qsTr("Local server IP ")
            font.family: "Verdana"
        }

        Label {
            id: label2
            x: 8
            y: 70
            text: qsTr("Public server IP")
        }

        Image {
            id: image1
            anchors.fill: parent
            z: -1
            source: "../../Pictures/comparison-of-youtube-media-types.png"
        }
}

