import QtQuick 2.0
import QtQuick.Window 2.14
import QtLocation 5.6
import QtPositioning 5.6
import io.qt.examples.gps_data 1.0


Window {
    id: window
    width: Qt.platform.os == "android" ? Screen.width : 512
    height: Qt.platform.os == "android" ? Screen.height : 512
    visible: true

    GPSData {
       id: gpsData
    }

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
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(gpsData.longitude, gpsData.latitude)
        zoomLevel: 18

        MapCircle {
            visible: (gpsData.status === "True") ? true : false
            center {
                latitude: gpsData.longitude
                longitude: gpsData.latitude
            }
            radius: 5.0
            color: 'blue'
            border.width: 3
        }
    }

    Rectangle {
        id: infoRect
        width: 200; height: 50
        x: (window.width / 2) - (infoRect.width / 2); y:(window.height / 2) - (infoRect.height/ 2)
        color: "lightgray"
        visible: (gpsData.status === "False") ? true : false

        Text {
            id: infoText
            text: "Waiting for GPS fix ..."
            anchors.horizontalCenter: infoRect.horizontalCenter
            font.pointSize: 11; font.bold: true;
        }
    }

    Rectangle {
        id: page
        width: 200; height: 100
        color: "lightgray"
        opacity: 0.75

        Text {
            id: longitude
            text: "Longitude: " + gpsData.longitude + "°"
            x: 5; y: 0
            font.pointSize: 11; font.bold: true;
        }

        Text {
            id: latitude
            text: "Latitude: " + gpsData.latitude + "°"
            x: 5; y: 15
            font.pointSize: 11; font.bold: true
        }

        Text {
            id: altitude
            text: "Altitude: " + gpsData.altitude + "m"
            x: 5; y: 30
            font.pointSize: 11; font.bold: true
        }

        Text {
            id: time
            text: "Time: " + gpsData.time
            x: 5; y: 45
            font.pointSize: 11; font.bold: true
        }

        Text {
            id: hasFix
            text: "Has fix: " + gpsData.status
            x: 5; y: 60
            font.pointSize: 11; font.bold: true
        }
    }
}
