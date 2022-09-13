QT += widgets core qml quick location

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -Wall -Wextra -Wno-narrowing -std=c++11 -shared -fPIC -O3 -mtune=native -march=native -DNDEBUG -fopenmp -ltbb
QMAKE_LFLAGS += -DHAVE_CBLAS=1

LIBS += -lblas -llapack -ltbb -lserial

INCLUDEPATH += headers/

SOURCES += \
    src/CustomCursor.cpp \
    src/GPSData.cpp \
    src/GroundControlStation.cpp \
    src/main.cpp\
    src/gps_driver/GPSFix.cpp \
    src/gps_driver/GPSService.cpp \
    src/gps_driver/NMEACommand.cpp \
    src/gps_driver/NMEAParser.cpp \
    src/gps_driver/NumberConversion.cpp \
    src/gps_driver/drotek_f9p_rover.cpp \
    src/gps_driver/HAL_Sirius_F9P_Rover.cc

HEADERS += \
    headers/CustomCursor.h \
    headers/GPSData.h \
    headers/GroundControlStation.h \
    headers/gps_driver/nmeaparse/* \
    headers/mavlink/v2.0/AGU/checksum.h \
    headers/mavlink/v2.0/AGU/mavlink_conversions.h \
    headers/mavlink/v2.0/AGU/mavlink_conversions.h \
    headers/mavlink/v2.0/AGU/mavlink_get_info.h \
    headers/mavlink/v2.0/AGU/mavlink_helpers.h \
    headers/mavlink/v2.0/AGU/mavlink_sha256.h \
    headers/mavlink/v2.0/AGU/mavlink_types.h \
    headers/mavlink/v2.0/AGU/message.hpp \
    headers/mavlink/v2.0/AGU/msgmap.hpp \
    headers/mavlink/v2.0/AGU/protocol.h\
    headers/mavlink/v2.0/AGU/common/* \
    headers/mavlink/v2.0/AGU/minimal/* \
    headers/mavlink/v2.0/AGU/AGU_MAVLINK/*

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

CONFIG += qmltypes
QML_IMPORT_NAME = io.qt.examples.gps_data
QML_IMPORT_MAJOR_VERSION = 1

DISTFILES += \
    readme.md \
    presentation_image.png \
    import_tiles.sh \
    .gitignore \
    simulate_flying_vehicle/* \
    message_definitions/v1.0/*
