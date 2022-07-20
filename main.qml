import QtQuick 2.0
import QtQuick.Window 2.14
import QtLocation 5.6
import QtPositioning 5.6

Window {
    width: Qt.platform.os == "android" ? Screen.width : 512
    height: Qt.platform.os == "android" ? Screen.height : 512
    visible: true

    Plugin {
        id: mapPlugin
        name: "osm" // "mapboxgl", "esri", ...
        // specify plugin parameters if necessary
        // PluginParameter {
        //     name:
        //     value:
        // }
    }

    Map {
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(59.91, 10.75) // Oslo
        zoomLevel: 14
    }

    Rectangle {
        id: page
        width: 200; height: 100
        color: "lightgray"
        opacity: 0.75

        Text {
            id: longitude
            text: "Longitude: "
            x: 5; y: 0
            font.pointSize: 11; font.bold: true;
        }

        Text {
            id: latitude
            text: "Latitude: "
            x: 5; y: 15
            font.pointSize: 11; font.bold: true
        }

        Text {
            id: altitude
            text: "Altitude: "
            x: 5; y: 30
            font.pointSize: 11; font.bold: true
        }

        Text {
            id: time
            text: "Time: "
            x: 5; y: 45
            font.pointSize: 11; font.bold: true
        }

        Text {
            id: hasFix
            text: "Has fix: False"
            x: 5; y: 60
            font.pointSize: 11; font.bold: true
        }
    }
}
