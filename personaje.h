#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
class Personaje : public QObject,  public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Personaje(QObject* parent=nullptr);
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
    qreal rowPixmap, colPixmap,  width, height, posX, posY;

};

#endif // PERSONAJE_H
