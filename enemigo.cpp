#include "enemigo.h"

enemigo::enemigo(int x, int y, int w, int h)
{
    this->posx = x;
    this->posy = y;
    this->width=w;
    this->height=h;
    setPos(posx, posy);
}

enemigo::enemigo(QObject *parent):QObject{parent}
{
    rowPixmap = 0;
    colPixmap = 0;
    posx = 0 ;
    posy = 0;
    width = 49;
    height = 59;
    stripe = new QPixmap (":/planeta-tierra.png");
    timer = new QTimer;
    timer->start(200);
}
QRectF enemigo::boundingRect() const
    //QRectF bolita::boundingRect() const
{
    return QRectF(posx, posy, width, height);

}
void enemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/planeta-tierra.png");
    painter->drawPixmap(boundingRect(), pixmap, pixmap.rect());


}
void enemigo::moveLeft()
{
    posx-=velocidad;
    setPos(posx, posy);
}

void enemigo::moveRight()
{
    posx+=velocidad;
    setPos(posx, posy);
}

void enemigo::moveUp()
{
    posy-=velocidad;
    setPos(posx, posy);
}

void enemigo::moveDown()
{
    posy+=velocidad;
    setPos(posx, posy);
}

void enemigo::actualizarPersonaje()
{

}
