import QtQuick 2.4
import QtQuick.Controls 1.4

ApplicationWindow {
	title: "DataBase"
	width: 600
	height: 450
    visible: true

	Item {
		anchors.fill: parent

		Column {
			anchors.centerIn: parent
			spacing: 15

			Label {
				text: DataBase.name
				anchors.horizontalCenter: parent.horizontalCenter
			}

			Button {
				text: "Button"
				onClicked: DataBase.getName(1)
				anchors.horizontalCenter: parent.horizontalCenter
			}

			Row {
				anchors.horizontalCenter: parent.horizontalCenter
				ListView {
					width: 100; height: 200
					model: DataBase.getNames()
					delegate: Text {
						text: modelData
					}
				}

				ListView {
					width: 100; height: 200
					model: DataBase.getFamilys()
					delegate: Text {
						text: modelData
					}
				}
			}
		}
	}
}
