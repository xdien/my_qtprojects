#-------------------------------------------------
#
# Project created by QtCreator 2014-08-11T09:46:40
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = opencv_detectMultiObjects
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp
INCLUDEPATH += /usr/include/opencv
LIBS += -lopencv_core\
-l opencv_imgproc \
-lopencv_highgui \
-lopencv_ml \
-lopencv_video \
-lopencv_features2d \
-lopencv_calib3d \
-lopencv_objdetect \
-lopencv_contrib \
-lopencv_legacy \
-lopencv_flann
