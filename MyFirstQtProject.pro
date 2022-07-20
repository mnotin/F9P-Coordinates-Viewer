QT += widgets core quick location

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -Wall -Wextra -Wno-narrowing -std=c++11 -shared -fPIC -O3 -mtune=native -march=native -DNDEBUG -fopenmp -ltbb
QMAKE_LFLAGS += -DHAVE_CBLAS=1

LIBS += -lblas -llapack -ltbb -lserial

SOURCES += \
    src/MyWindow.cpp \
    src/main.cpp\
    src/gps_driver/GPSFix.cpp \
    src/gps_driver/GPSService.cpp \
    src/gps_driver/NMEACommand.cpp \
    src/gps_driver/NMEAParser.cpp \
    src/gps_driver/NumberConversion.cpp \
    src/gps_driver/drotek_f9p_rover.cpp \
    src/gps_driver/HAL_Sirius_F9P_Rover.cc

HEADERS += \
    headers/MyWindow.h \
    headers/gps_driver/nmeaparse/Event.h \
    headers/gps_driver/nmeaparse/GPSFix.h \
    headers/gps_driver/nmeaparse/GPSService.h \
    headers/gps_driver/nmeaparse/nmea.h \
    headers/gps_driver/nmeaparse/NMEACommand.h \
    headers/gps_driver/nmeaparse/NMEAParser.h \
    headers/gps_driver/nmeaparse/NumberConversion.h

RESOURCES += qml.qrc \
    qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
