#include "mainwindow.h"
#include "../ui_mainwindow.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    //,a(0)
{

    ui->setupUi(this);
    setWindowTitle("flappy bird");//set title of window

    QIcon icon(":/Images/bird.ico");//set icon of window
    setWindowIcon(icon);

    son=new graphicsView(this);






}

MainWindow::~MainWindow()
{

    delete ui;
}

