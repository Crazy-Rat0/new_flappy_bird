#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include <QObject>
#include"../common/map.h"
class viewmodel:public QObject
{
    Q_OBJECT

public:
    explicit viewmodel(QObject *parent = nullptr,map* a_map=nullptr);
    ~viewmodel();

    map* map() const;

    bool birdIsDead() const;
    int birdX() const;
    int birdY() const;

public slots:
    void updateGame();
    void onFly();
    void onDrop();
    void onReset();

signals:
    void gameUpdated();
    void gameOver();
    void birdIsDeadChanged();
    void birdXChanged();
    void birdYChanged();


public:
    class map* m_map;
};

#endif // VIEWMODEL_H
