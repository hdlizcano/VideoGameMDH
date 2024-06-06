#include "mainwindow.h"
#include "ui_mainwindow.h"
/*#include <QGraphicsScene>
#include <QGraphicsView>
#include <personaje.h>*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    personaje = new Personaje;
    Enemigo = new enemigo;
    //scene->setSceneRect(0, 0, 482, 610);
    scene->setSceneRect(0,0,ui->graphicsView->width(), ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(scene->width()+5, scene->height()+5);
    this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);
    scene->addItem(personaje);
    scene->addItem(Enemigo);
    personaje->setPos(0, 0);
    Enemigo->setPos(35,10);
}

MainWindow::~MainWindow()
{
    delete personaje;
    delete scene;
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (personaje !=nullptr){
        if(event->key()==Qt::Key_A){
            personaje->moveLeft();
            //personaje->setPo
                    }
        else if(event->key() ==Qt::Key_D){
            personaje->moveRight();
        }
                    else if(event->key() ==Qt::Key_W){
                        personaje->moveUp();
    }
        else if(event->key() ==Qt::Key_S){
            personaje->moveDown();
}
    }
}
