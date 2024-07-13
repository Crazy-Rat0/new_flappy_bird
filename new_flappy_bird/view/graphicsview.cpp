#include "graphicsview.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPoint>
#include <QPointF>

graphicsView::graphicsView(QWidget* parent) : QGraphicsView(parent), view_map(nullptr)
{
    scene_view = new QGraphicsScene();

    QPixmap bird(":/Images/bird2.png");
    QPixmap pipe_upper(":/Images/pipe1.png");
    QPixmap pipe_lower(":/Images/pipe2.png");

    bird_view = new QGraphicsPixmapItem(bird);
    scene_view->addItem(bird_view);

    for (int i = 0; i < pipe_count; i++) {
        QGraphicsPixmapItem *pipe_upper_view = new QGraphicsPixmapItem(pipe_upper);
        QGraphicsPixmapItem *pipe_lower_view = new QGraphicsPixmapItem(pipe_lower);
        pipes_view.append(pipe_upper_view);
        pipes_view.append(pipe_lower_view);
    }
    for (QGraphicsPixmapItem *pipe_view : pipes_view) {
        scene_view->addItem(pipe_view);
    }




    ResetBtn=new QPushButton(this);
    ResetBtn->move(170,242);
    ResetBtn->hide();
    ResetBtn->setStyleSheet("background-image: url(:/Images/replay.png);"
                            );

    GameOver=new QLabel(this);
    GameOver->setFixedSize(256,57);
    GameOver->move(65,140);
    GameOver->hide();
    GameOver->setStyleSheet("background-image: url(:/Images/gameover.png);"
                            );

    this->setScene(scene_view);
    this->setSceneRect(-192, -224, 384, 448);
}


void graphicsView::redrawBird()
{
    int x = view_map->getBird()->getX(); // 你的 MainWindow 坐标系下的 x 值
    int y = view_map->getBird()->getY(); // 你的 MainWindow 坐标系下的 y 值

    // 将 mainWindowPos 中的 y 坐标转换为视图坐标
    QPoint viewPosY = this->mapFromParent(QPoint(x, y));

    // 将视图坐标转换为场景坐标
    QPointF scenePos = this->mapToScene(viewPosY);

    // 设置 bird_view 在场景中的位置
    bird_view->setPos(scenePos);
}

void graphicsView::redrawPipes() {
    for (QGraphicsPixmapItem* pipe_view : pipes_view) {
        pipe* pipe = view_map->getPipes().at(pipes_view.indexOf(pipe_view));

        QPoint viewPosX;
        if (pipe->isUpper()) {
            viewPosX = this->mapFromParent(QPoint(pipe->getX(), pipe->getH() - 250));
        }
        else {
            viewPosX = this->mapFromParent(QPoint(pipe->getX(), 448 - pipe->getH()));
        }
        QPointF scenePos = this->mapToScene(viewPosX);
        pipe_view->setPos(scenePos);
    }
}

void graphicsView::gameOver()
{
    qDebug() << "over1";
    if(view_map->getBird()->isDead())
    {
        qDebug() << "show over";
        this->ResetBtn->show();
        this->GameOver->show();
    }
    else
    {
        this->ResetBtn->hide();
        this->GameOver->hide();
    }
}

void graphicsView::mousePressEvent(QMouseEvent *event)
{
    //如果单击了就触发clicked信号
    if (event->button() == Qt::LeftButton)
    {
        //触发clicked信号
        emit clicked();
    }
}

void graphicsView::setMap(map* inMap)
{
    this->view_map = inMap;
}
