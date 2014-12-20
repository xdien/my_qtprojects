#-------------------------------------------------
#
# Project created by QtCreator 2014-08-12T18:08:51
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = opencv_faceDetect3
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp
INCLUDEPATH += /usr/include/opencv
LIBS += -lopencv_core\
-lopencv_imgproc \
-lopencv_highgui \
-lopencv_ml \
-lopencv_video \
-lopencv_features2d \
-lopencv_calib3d \
-lopencv_objdetect \
-lopencv_contrib \
-lopencv_legacy \

HEADERS += \
    cvhaartraining.h
