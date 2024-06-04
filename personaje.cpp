#include "personaje.h"

//**REVISAR CON DANIEL** Personaje::Personaje() {}

Personaje::Personaje(QObject *parent)
    : QObject{parent}
{
    rowPixmap = 0;
    colPixmap = 0;
    width = 16;
    height = 16;
    stripe = new QPixmap(":/bomberman_stripe.png");
    timer = new QTimer;
    timer->start(200);
    connect(timer, &QTimer::timeout, this, Personaje::actualizarPersonaje);
}
QRectF Personaje::boundingRect() const
{
    return QRectF(0, 0, width, height);
}
void Personaje::actualizarPersonaje()
{
    colPixmap += width;
    if(colPixmap >= 1841){
        colPixmap = 0;
        rowPixmap += height;
        if(rowPixmap >= 2400){
            rowPixmap = 0;
        }
    }
    update(0, 0, width, height);
}
void Personaje::paint(QPainter* painter, const QStyleOptionGraphicsItem*
                                             option, QWidget* widget)
{
    painter->drawPixmap(0, 0, *stripe, colPixmap, rowPixmap, width, height);
}
