#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QTimer>
#include"../common/map.h"


class graphicsView:public QGraphicsView
{
    Q_OBJECT
public:
    graphicsView(QWidget* parent=nullptr);
public:
    QGraphicsScene* scene_view;
    QGraphicsPixmapItem* bird_view;
    QGraphicsPixmapItem* GameOver_view;
    void setMap(map* inMap);
    map* View_map;
    QTimer* drop_timer;
public slots:
    void redraw();
signals:
    //自定义clicked()信号,在mousePressEvent事件发生时触发
    void clicked();
protected:
    virtual void mousePressEvent(QMouseEvent *event);
};

#endif // GRAPHICSVIEW_H
