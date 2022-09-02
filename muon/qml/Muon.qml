import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Window 2.14
import QtQuick.Layouts 1.14

Window {
  id: _window
  width: 740; height: 420
  visible: true
  color: "#212121"


  PlaylistView {
    id: _view
    anchors {
      top: parent.top; left: parent.left; right: parent.right
      bottom: _controls.top
    }
  }

  Controls {
    id: _controls
    height: 70
    anchors {
      left: parent.left; right: parent.right
      bottom: parent.bottom
    }
  }



}