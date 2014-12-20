import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: 480
    height: 800
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Image {
        id: image1
        anchors.fill: parent
        sourceSize.width: 331
        fillMode: Image.Stretch
        source: "qrc:/qtquickplugin/images/template_image.png"
    }
}
