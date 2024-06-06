#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <personaje.h>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <enemigo.h>
#include<QList>
#include<QTimer>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Personaje *personaje;
    enemigo *Enemigo;


};
#endif // MAINWINDOW_H
