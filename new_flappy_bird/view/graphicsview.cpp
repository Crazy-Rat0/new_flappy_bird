#include "graphicsview.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPoint>
#include <QPointF>

graphicsView::graphicsView(QWidget* parent):QGraphicsView(parent),View_map(nullptr)
{
        QPixmap a(":/Images/bird2.png");

         bird_view= new QGraphicsPixmapItem(a);

        scene_view=new QGraphicsScene;//

        scene_view->addItem(bird_view);


        this->setScene(scene_view);
        this->setFixedSize(384,448);

        ResetBtn=new QPushButton(this);
        ResetBtn->move(170,242);
        ResetBtn->hide();
        ResetBtn->setStyleSheet("background-image: url(:/Images/replay.png);"
                                );







}


void graphicsView::redraw()
{
    QGraphicsView *view = this;//scene_view->views().first();



    // 步骤 1: 获取 bird_view 在场景坐标系中的位置
    QPointF scenePos = bird_view->pos(); // bird_view->pos() 返回项在场景中的坐标

    // 步骤 2: 将场景坐标转换为视图坐标（这里场景坐标已经是从pos()获得的）
    QPointF viewPos = view->mapFromScene(scenePos); // 将场景坐标转换为视图坐标

    // 步骤 3: 将视图坐标转换为 MainWindow 的坐标
    QPoint mainWindowPos = view->mapToParent(viewPos.toPoint()); // 将视图坐标转换为父窗口坐标

    int newY = View_map->bird()->y(); // 你的 MainWindow 坐标系下的 y 值

    // 将 mainWindowPos 中的 y 坐标转换为视图坐标
    QPoint viewPosY = view->mapFromParent(QPoint(mainWindowPos.x(), newY));

    // 将视图坐标转换为场景坐标
    scenePos = view->mapToScene(viewPosY);

    // 设置 bird_view 在场景中的位置
    bird_view->setPos(scenePos);


    if(View_map->bird()->isDead())
    {
        this->ResetBtn->show();
    }
    else
    {
        this->ResetBtn->hide();
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
    //将该事件传给父类处理
    //QLineEdit::mousePressEvent(event);
}
void graphicsView::setMap(map* inMap)
{
    this->View_map = inMap;
}
