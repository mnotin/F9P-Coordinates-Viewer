# F9P Coordinates Viewer
A small application written in C++ with Qt and QML to display the coordinates of the F9P GNSS on an interactive map.

![Presentation image](presentation_image.png)

## Build
The application targets Qt 5.15 LTS.

### Libraries
To compile the project, you will need the following dependencies:
- [libserial](https://github.com/crayzeewulf/libserial/)
- [lapack](https://netlib.org/lapack/)
- [tbb](https://github.com/oneapi-src/oneTBB)
- [qt5](https://www.qt.io/)
- [qt5-location](https://www.qt.io/)
- [qt5-quickcontrols](https://www.qt.io/)

## Credits
The original version of the GNSS driver used in the project comes from [here](https://github.com/lapo5/HAL-Drotek-F9P).
