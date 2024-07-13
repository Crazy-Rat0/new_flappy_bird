#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include <QObject>
#include"../common/map.h"

class viewmodel : public QObject
{
    Q_OBJECT

public:
    explicit viewmodel(QObject *parent = nullptr, map* a_map=nullptr);
    ~viewmodel();

    map* getMap() const;

    void onDrop();
    void updateBird();
    void updatePipes();

public slots:
    void updateGame();
    void onFly();
    void onReset();

signals:
    void birdYChanged();
    void pipesMoved();

    void gameOver();

private:
    bool detectCollision();
    map* m_map;
};

#endif // VIEWMODEL_H
