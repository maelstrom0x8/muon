import QtQuick 2.14
import QtQuick.Controls 2.14


Item {
  id: _root


  Component {
    id: _listdelg
    Rectangle {
      readonly property ListView __lv: ListView.view
      id: _rect
      width: __lv.width ; height: 50
      color: __lv.currentIndex == index ? Qt.darker("#414141"): "#424242"
      Text{
        id: titleTxt
        anchors {
          left: parent.left; leftMargin: 8; top: parent.top; topMargin: 14
        }

        text: title
        color: __lv.currentIndex == index ? "#efefef": "#efefef"
        font.pixelSize: 12
      }
      Text {
        id: artistTxt
        text: artist
        anchors {
          left: parent.left; leftMargin: 8; top: titleTxt.bottom; topMargin: 2;
          verticalCenter: parent.verticalCenter
        }
        font.pixelSize: 10
      }
      Rectangle{
        id: _sep
        width: parent.width
        height: 4
        color: "#414141"
        anchors {
          bottom: parent.bottom; horizontalCenter: parent.horizontalCenter
        }
      }
      MouseArea{
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: (mouse) => {
          if(mouse.button === Qt.LeftButton) {
            __lv.currentIndex = index;
          }
          else {
            __lv.currentIndex = index;
          }
        }
        onDoubleClicked: (mouse) => {
          if(mouse.button == Qt.LeftButton) {
            console.log(file)
          }
        }
      }
    }
  }

  Rectangle {
    id: container_
    anchors.fill: parent
    color: "#212121"

    ListView {
      id: _lv
      width: parent.width; height: parent.height
      anchors.margins: 2
      anchors.left: parent.left
      model: __model
      delegate: _listdelg
      clip: true
      keyNavigationWraps: true

    }
  }
}
