TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
INCLUDEPATH += /usr/include/opencv
#INCLUDEPATH += /home/xdien/AndroidStudioProjects/OpenCV-2.4.9-android-sdk/sdk/native/jni/include
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

#LIBS += /home/xdien/AndroidStudioProjects/OpenCV-2.4.9-android-sdk/sdk/native/libs/armeabi-v7a/*

HEADERS += \
    ../../AndroidStudioProjects/ImageEdit/app/jni/com_crazy_xdien_imageedit_sliding_process_jniMatEffects.h \
    ../../AndroidStudioProjects/ImageEdit/app/jni/com_crazy_xdien_imageedit_sliding_MainActivity.h \
    ../../AndroidStudioProjects/ImageEdit/app/jni/com_crazy_xdien_imageedit_sliding_MainActivity_SlideMenuClickListener.h \
    ../../AndroidStudioProjects/ImageEdit/app/jni/com_crazy_xdien_imageedit_sliding_sliding_EffectFragment.h
