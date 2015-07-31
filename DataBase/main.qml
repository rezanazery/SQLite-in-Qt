import QtQuick 2.4
import QtQuick.Controls 1.3

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true

	Item {
		anchors.fill: parent

		Column {
			anchors.centerIn: parent
			spacing: 15

			Label {
				id: lbl
				text: DataBase.name
				anchors.horizontalCenter: btn.horizontalCenter
			}

			Button {
				id: btn
				text: "Button"
			}
		}
	}
}
