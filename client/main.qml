import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.3
import QtQuick.Layouts 1.12
import com.drawbot.org 1.0
import Qt.labs.platform 1.0

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: "drawbot"

    FileDialog {
        function urlToPath(urlString) {
            var s
            if (urlString.startsWith("file:///")) {
                var k = urlString.charAt(9) === ':' ? 8 : 7
                s = urlString.substring(k)
            } else {
                s = urlString
            }
            return decodeURIComponent(s);
        }

        id: fileDialog
        folder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
        nameFilters: [ "Image files (*.jpg *.png)" ]
        onAccepted: ImageController.loadImage(fileDialog.urlToPath(fileDialog.file.toString()))
    }

    header: ColumnLayout {
        Slider {
            id: sliderThreshold
            Layout.fillWidth: true
            from: 0
            to: 255
            onValueChanged: ImageController.threshold = value
            Connections {
                target: ImageController
                onThresholdChanged: sliderThreshold.value = ImageController.threshold
            }
        }
    }

    ImageItem {
        id: imageDisplayed
        scale: ImageController.imageLoaded ? 1 : 0.5
        anchors.fill: parent
        transformOrigin: Item.Center

        MouseArea {
            anchors.fill: parent
            onClicked: if(!ImageController.imageLoaded) fileDialog.open()
        }
    }

    Connections {
        target: ImageController
        onImageChanged: imageDisplayed.image = ImageController.image
    }

    BusyIndicator {
        anchors.centerIn: parent
        running: ImageController.loading
    }

    footer: RowLayout {
        width: parent.width

        RoundButton {
            text: "\u274c"
            Layout.alignment: Qt.AlignHCenter
            onClicked: ImageController.clearImage()
        }

        RoundButton {
            text: "\u21ba"
            Layout.alignment: Qt.AlignHCenter
            onClicked: ImageController.resetImage()
        }

        RoundButton {
            text: "\u2713"
            Layout.alignment: Qt.AlignHCenter
        }
    }

}


