#
# This is your project .pro file
#
# This file was automatically generated by running:
#
#    qmake -project
#
# You only need to run that command once, and afterwards you can
# modify this file from then by hand.
#

# The "app" template means we want to build an application rather
# than a library or other kind of project
TEMPLATE = app

# Some variables that help the compiler do its thing:
DEPENDPATH += .
INCLUDEPATH += .

# This gives us access to the Qt socket classes (QTcpSocket)
QT += network

# This bundles any images we want right into our executable, so
# we do not have to ship any image files with our installer or RPM
# or deb package or whatever:
RESOURCES += images.qrc

# This is our list of files in the project. You can add files
# to these lists as you add new windows, custom widgets, or new
# functionality:

FORMS   += MainWindow.ui 

HEADERS += MainWindow.h 

SOURCES += MainWindow.cxx \
           main.cpp

