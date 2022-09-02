import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14

Item {
  id: _root

  Rectangle {
    id: _container
    anchors.fill: parent
    color: "#494949"

    Button {
        id: _playback
        width: 30; height: 30
        anchors {top: parent.top; topMargin: 30; left: parent.left; leftMargin: 10}
    }

    RowLayout {
      id: _layout
      spacing: 4
      anchors {left: _playback.right; leftMargin: 30;top: parent.top; topMargin: 30}

      Button {
        id: _previous
        Layout.maximumWidth: 30
        Layout.maximumHeight: 30
        
      }

      Button {
        id: _stop
        Layout.maximumWidth: 30
        Layout.maximumHeight: 30
      }

      Button {
        id: _next
        Layout.maximumWidth: 30
        Layout.maximumHeight: 30
      
      }

      Button {
        id: _shuffle
        Layout.maximumWidth: 30
        Layout.maximumHeight: 30
        Layout.leftMargin: 10
      }

    }

    RowLayout {
      id: _volumeControlLayout
      anchors {
        right: parent.right; rightMargin: 32
        top: parent.top; topMargin: 30
        

      }
      Button {
        id: _mute
        Layout.maximumWidth: 30
        Layout.maximumHeight: 30
        Layout.alignment: Qt.AlignRight
        
      }


      Slider {
        id: _volume
        
        Layout.maximumWidth: 80
        Layout.alignment: Qt.AlignRight
      }

    }
  }
}