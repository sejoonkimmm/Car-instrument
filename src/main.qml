import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: root
    width: 1280
    height: 400
    color: "#36454F"
    visible: true
    title: qsTr("Instrument Cluster")


    Rectangle {
        id: gauge
        width: 360
        height: 360

        color: "#ff0000"

        anchors.centerIn: parent
        radius: width/2

        border {
            width: 10
            // color: "#000000"
        }

        Rectangle {
            id: gaugeCenterDot

            width: 20
            height: 20

            color: "#000000"

            anchors.centerIn: parent

            radius: width/2
        }

        Rectangle {
            id: needle

            width: 160
            height: 10

            color: "#000000"
            anchors {
                bottom: parent.verticalCenter
                bottomMargin: -(gaugeCenterDot.width / 4)
                right: parent.horizontalCenter
            }

            transformOrigin: Item.Right
            rotation: -30

            SequentialAnimation on rotation {
                PropertyAnimation {
                    from: -30
                    to: 210
                    duration: 5000
                }
            }
        }

        function degreesToRadians(degrees)
        {
          var pi = Math.PI
          return degrees * (pi/180)
        }

        Repeater {
            model: 9
            Rectangle {
                width: 30
                height: 10
                x: (parent.width / 2) + (180 * Math.sin(parent.degreesToRadians(-60 - index * 30)))
                y: (parent.height / 2) + (180 * Math.cos(parent.degreesToRadians(-60 - index * 30))) - (needle.height/2)
                transformOrigin: Item.Left
                rotation: -30 + index * 30
            }
        }
    }
}
