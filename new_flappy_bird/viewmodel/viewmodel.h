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


signals:
    void gameUpdated();
    void gameOver();
    void birdIsDeadChanged();
    void birdXChanged();
    void birdYChanged();
    void birdY2Changed();//debug 用，记得删除

private:
    class map* m_map;
};

#endif // VIEWMODEL_H
