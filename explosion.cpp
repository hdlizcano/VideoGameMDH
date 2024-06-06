// explosion.cpp
#include "explosion.h"

Explosion::Explosion(QObject *parent) : QObject(parent)
{
    timer = new QTimer();
    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(":/imagenes/explosion.png");

    ancho = 105;
    alto  = 144;

    scaleWidth = 2.0;
    scaleHeight = 2.0;

    timer->start(400);

    connect(timer,&QTimer::timeout,this,&Explosion::Actualizacion);
}

void Explosion::Actualizacion()
{
    columnas +=105;
    if(columnas >=423)
    {
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho*scaleWidth,alto*scaleHeight);
}

QRectF Explosion::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho*scaleWidth,alto*scaleHeight);
}

void Explosion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap scaledPixmap = pixmap->copy(columnas, 1, ancho, alto).scaled(ancho*scaleWidth, alto*scaleHeight, Qt::KeepAspectRatio);
    painter->drawPixmap(-ancho/2,-alto/2, scaledPixmap);
}
