#include "graphicsview.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPoint>
#include <QPointF>
#include <QString>

graphicsView::graphicsView(QWidget* parent) : QGraphicsView(parent), view_map(nullptr)
{
    scene_view = new QGraphicsScene();
    this->setScene(scene_view);
//    this->setFixedSize(384, 448);
    this->setSceneRect(-192, -224, 384, 448);

    QPixmap bird(":/Images/bird2.png");
    QPixmap pipe_upper(":/Images/pipe1.png");
    QPixmap pipe_lower(":/Images/pipe2.png");
    QPixmap all_score_board(":/Images/scoreboard.png");
    all_score_board = all_score_board.scaled(200, 102);
    QRect rect(120, 0, 150, 102);
    QPixmap score_board = all_score_board.copy(rect);

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

    score_board_view = new QGraphicsPixmapItem(score_board);
    scene_view->addItem(score_board_view);
    score_board_view->setPos(QPoint(-192, -224));

    current_score = new QGraphicsTextItem(QString::number(0));
    best_score = new QGraphicsTextItem(QString::number(0));
    scene_view->addItem(current_score);
    scene_view->addItem(best_score);
    current_score->setPos(-158, -200);
    best_score->setPos(-158, -160);


    ResetBtn = new QPushButton(this);
    ResetBtn->move(170, 242);
    ResetBtn->hide();
    ResetBtn->setStyleSheet("background-image: url(:/Images/replay.png);");

    GameOver = new QLabel(this);
    GameOver->setFixedSize(256,57);
    GameOver->move(65,140);
    GameOver->hide();
    GameOver->setStyleSheet("background-image: url(:/Images/gameover.png);");
}


void graphicsView::redrawBird()
{
    int x = view_map->getBird()->getX(); // 你的 MainWindow 坐标系下的 x 值
    int y = view_map->getBird()->getY(); // 你的 MainWindow 坐标系下的 y 值

    // 将 mainWindowPos 中的 y 坐标转换为视图坐标
    QPoint viewPos = this->mapFromParent(QPoint(x, y));

    // 将视图坐标转换为场景坐标
    QPointF scenePos = this->mapToScene(viewPos);

    // 设置 bird_view 在场景中的位置
    bird_view->setPos(scenePos);
}

void graphicsView::redrawPipes() {
    for (QGraphicsPixmapItem* pipe_view : pipes_view) {
        pipe* pipe = view_map->getPipes().at(pipes_view.indexOf(pipe_view));

        QPoint viewPos;
        if (pipe->isUpper()) {
            viewPos = this->mapFromParent(QPoint(pipe->getX(), pipe->getH() - 250));
        }
        else {
            viewPos = this->mapFromParent(QPoint(pipe->getX(), 448 - pipe->getH()));
        }
        QPointF scenePos = this->mapToScene(viewPos);
        pipe_view->setPos(scenePos);
    }
}

void graphicsView::updateScore() {
    int score = view_map->getScoreBoard()->getScore();
    qDebug() << "current score:" << score;
    current_score->setPlainText(QString::number(score));
}

void graphicsView::updateBestScore() {
    int best = view_map->getScoreBoard()->getBest();
    qDebug() << "best score" << best;
    best_score->setPlainText(QString::number(best));
}

void graphicsView::gameOver()
{
    qDebug() << "gameover";
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
