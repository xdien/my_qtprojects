#-------------------------------------------------
#
# Project created by QtCreator 2014-08-16T03:20:31
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = opencv_ss
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp
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
