import QtQuick 2.0
import QtQuick.Window 2.14
import QtQuick.Controls 1.4
import QtLocation 5.8
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

    CustomCursor {
       id: customCursor
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: Plugin {
            id: mapPlugin
            name: "osm"
             PluginParameter {
                 name: "osm.mapping.offline.directory"
                 value: ":/Offline_tiles/"
            }
        }
        activeMapType: map.supportedMapTypes[2]
        center: QtPositioning.coordinate(gpsData.longitude, gpsData.latitude)
        zoomLevel: 1

        MapQuickItem {
            id: gpsCursor
            sourceItem: Rectangle { width: 20; height: 20; color: "red"; border.width: 2; border.color: "black"; smooth: true; radius: 15 }
            coordinate : QtPositioning.coordinate(gpsData.longitude, gpsData.latitude)
            opacity: 1.0
            anchorPoint: Qt.point(sourceItem.width/2, sourceItem.height/2)
            visible: gpsData.hasFix
        }

        MapQuickItem {
            id: customCursorIcon
            sourceItem: Rectangle { width: 20; height: 20; color: "yellow"; border.width: 2; border.color: "black"; smooth: true; radius: 15 }
            coordinate : QtPositioning.coordinate(customCursor.latitude, customCursor.longitude)
            opacity: 1.0
            anchorPoint: Qt.point(sourceItem.width/2, sourceItem.height/2)
            visible: customCursor.latitudeIsSet && customCursor.longitudeIsSet
        }
    }

    Rectangle {
        id: gpsDataRectangle
        width: 200; height: 150
        color: "#FFD2D2D2"
        opacity: 0.75

        Text {
            id: longitude
            text: "Longitude: " + (gpsData.longitude).toFixed(5) + "°"
            x: 5; y: 0
            font.pointSize: 11; font.bold: true;
        }

        Text {
            id: latitude
            text: "Latitude: " + (gpsData.latitude).toFixed(5) + "°"
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
            text: "Has fix: " + gpsData.hasFix
            x: 5; y: 60
            font.pointSize: 11; font.bold: true
        }

        Text {
            id: latitudeLabel
            text: "Lat: "
            x: 5; y: 90
            font.pointSize: 11; font.bold: true
        }

        TextField {
            placeholderText: qsTr("Latitude  ...")
            x: latitudeLabel.x + 45 ; y: latitudeLabel.y

            onEditingFinished: text !== "" ? customCursor.latitude = text : customCursor.latitudeIsSet = false
        }

        Text {
            id: longitudeLabel
            text: "Long: "
            x: 5; y: 115
            font.pointSize: 11; font.bold: true
        }

        TextField {
            placeholderText: qsTr("Longitude ...")
            x: longitudeLabel.x + 45; y: longitudeLabel.y

            onEditingFinished: text !== "" ? customCursor.longitude = text : customCursor.longitudeIsSet = false
        }
    }
}
