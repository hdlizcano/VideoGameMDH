// sprite.h
#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit sprite(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    float filas,columnas;

    float ancho;
    float alto;

    // Agrega la variable 'contador' aquí
    int contador;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void Actualizacion();
};

#endif // SPRITE_H
