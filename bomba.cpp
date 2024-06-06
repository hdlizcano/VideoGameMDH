// sprite.cpp
#include "bomba.h"
#include "explosion.h" // Incluye el encabezado de la clase Explosion
#include <QGraphicsScene> // Incluye el encabezado de QGraphicsScene

sprite::sprite(QObject *parent) : QObject(parent)
{
    timer = new QTimer();
    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(":/imagenes/Capa 2.png");

    //dimensiones de c/U de las imagenes
    ancho = 144;
    alto  = 144;

    timer->start(400);// modifica la velocidad en que itera entre las imagenes

    connect(timer,&QTimer::timeout,this,&sprite::Actualizacion);

    // Inicializa el contador a 0
    contador = 0;
}

void sprite::Actualizacion()
{
    columnas +=144;
    if(columnas >=423)
    {
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);

    // Incrementa el contador
    contador++;

    // Si el contador llega a 10, detén el temporizador, oculta el sprite y crea una nueva Explosion
    if(contador == 10)
    {
        timer->stop();
        this->hide(); // Oculta el sprite

        // Crea una nueva Explosion
        Explosion *explosion = new Explosion();
        explosion->setPos(this->x() + this->ancho/2 - explosion->ancho, this->y() + this->alto/2 - explosion->alto); // Centra la explosión con respecto a la bomba
        this->scene()->addItem(explosion); // Añade la explosión a la escena
    }
}

QRectF sprite::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,1,ancho,alto);
}
