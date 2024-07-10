#include "graphicsview.h"
#include <QMouseEvent>
graphicsView::graphicsView(QWidget* parent):QGraphicsView(parent)
{
        QPixmap a(":/Images/bird2.png");

         bird_view= new QGraphicsPixmapItem(a);

        scene_view=new QGraphicsScene;
        scene_view->addItem(bird_view);

        this->setScene(scene_view);
        this->setFixedSize(384,448);
}


void graphicsView::redraw_bird(int y)
{
    bird_view->setPos(170,y);
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
