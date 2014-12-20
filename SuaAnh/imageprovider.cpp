#include "imageprovider.h"
#include <QtDeclarative/QDeclarativeImageProvider>

imageProvider::imageProvider() :QDeclarativeImageProvider(QDeclarativeImageProvider::Image)
{

}

QImage imageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    QImage image;
    image = QImage::fromData(m_baImmagine);
    *size = image.size();
    return image;
}


void imageProvider::caricaImmagineTelecamera(QByteArray ba_immagine)
{
    m_baImmagine = ba_immagine;
}
