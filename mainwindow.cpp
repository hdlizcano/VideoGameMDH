#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    personaje = new Personaje;
    scene->setSceneRect(0, 0, 1000, 1000);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(scene->width()+5, scene->height()+5);
    this->resize(ui->graphicsView->width()+100,
                 ui->graphicsView->height()+100);
    scene->addItem(personaje);
    personaje->setPos(0,0);
}
MainWindow::~MainWindow()
{
    delete personaje;
    delete scene;
    delete ui;
}
