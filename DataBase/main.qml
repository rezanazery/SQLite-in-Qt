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

//			Label {
//				id: resualt
//				text: "no resualt"
//				anchors.horizontalCenter: parent.horizontalCenter
//			}
			ListView {
				width: 200; height: 100
				model: DataBase.searchResualt
				delegate: Text {
					text: modelData
				}
			}

			TextField {
				id: input
				width: 100; height: 25
				placeholderText: "search in names"
				anchors.horizontalCenter: parent.horizontalCenter
			}

			Button {
				text: "Button"
				onClicked: DataBase.search_in_name(input.text)
				anchors.horizontalCenter: parent.horizontalCenter
			}

			Row {
				anchors.horizontalCenter: parent.horizontalCenter
				ListView {
					width: 100; height: 100
					model: DataBase.getNames()
					delegate: Text {
						text: modelData
					}
				}

				ListView {
					width: 100; height: 100
					model: DataBase.getFamiles()
					delegate: Text {
						text: modelData
					}
				}
			}
		}
	}
}
