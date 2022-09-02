import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtQuick.Layouts 1.14

Window {
  id: _window
  width: 740; height: 420
  visible: true
  color: "#212121"


  PlaylistView {
    id: _view
    anchors.fill: parent
  }


}