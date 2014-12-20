#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H
#include <QImage>
#include<QByteArray>
#include <QtDeclarative/QDeclarativeImageProvider>

class imageProvider
{
public:
    imageProvider();
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);
    void caricaImmagineTelecamera(QByteArray ba_immagine);
    QByteArray m_baImmagine;
};

#endif // IMAGEPROVIDER_H
