#include "mainwindow.h"
#include <QApplication>
#include <QtMultimedia/QCamera>
#include <QtMultimedia/QCameraViewfinderSettingsControl>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

       QCameraViewfinderSettingsControl * viewFinder;
       QCamera * camera;

   /* This did not help
       QByteArray cameraDevice;
       foreach(const QByteArray &deviceName, QCamera::availableDevices()) {
           if (cameraDevice.isEmpty())
               cameraDevice = deviceName;
       }
   */

       camera = new QCamera(); //(cameraDevice);
       viewFinder = new QCameraViewfinderSettingsControl;

       camera->setViewfinder(viewFinder);
       camera->start();

       return a.exec();
}
