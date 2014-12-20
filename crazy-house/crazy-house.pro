TEMPLATE = app

QT += qml quick
QMAKE_CFLAGS += -D LINUX

SOURCES += main.cpp
RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS +=

QMAKE_LFLAGS +=

OTHER_FILES += \
    ../../Pictures/comparison-of-youtube-media-types.png
