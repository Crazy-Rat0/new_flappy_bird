#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>

class graphicsView:public QGraphicsView
{
    Q_OBJECT
public:
    graphicsView(QWidget* parent=nullptr);
public:
    QGraphicsScene* scene_view;
    QGraphicsPixmapItem* bird_view;
public slots:
    void redraw_bird(int y);
};

#endif // GRAPHICSVIEW_H
