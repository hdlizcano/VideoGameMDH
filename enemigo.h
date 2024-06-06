#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
class enemigo: public QObject, public QGraphicsItem

{
    int posx, posy, width , height ,velocidad=3;
public:
    enemigo(int x, int y, int w, int h);
    explicit enemigo(QObject* parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
public slots:
    void actualizarPersonaje();
private:
    QTimer* timer;
    QPixmap* stripe;
    qreal rowPixmap, colPixmap; //,  width, height, posX, posY;
};

#endif // ENEMIGO_H
