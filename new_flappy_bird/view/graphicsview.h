#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include"../common/map.h"
#include <QPushButton>
#include <QLabel>


class graphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    graphicsView(QWidget* parent = nullptr);

    void setMap(map* inMap);

    const static int pipe_count = 32;
    QGraphicsScene* scene_view;
    QGraphicsPixmapItem* bird_view;
    QList<QGraphicsPixmapItem*> pipes_view;
    QLabel* GameOver;
    QPushButton* ResetBtn;
    map* view_map;
    QTimer* drop_timer;

public slots:
    void redrawBird();
    void redrawPipes();
    void gameOver();

signals:
    //自定义clicked()信号,在mousePressEvent事件发生时触发
    void clicked();

protected:
    virtual void mousePressEvent(QMouseEvent *event);
};

#endif // GRAPHICSVIEW_H
