#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QList>
#include <QRandomGenerator>
#include "bird.h"

class map : public QObject
{
    Q_OBJECT

public:

    explicit map(QObject *parent = nullptr);
    ~map();


//    void generatePipes();
//    void movePipes();
    void updateBird();
//    bool checkCollision();

    bird* bird() const;

signals:
    void pipesUpdated();
    void collisionDetected();

private:
//    QList<Pipe*> m_pipes;

//    int m_pipeCount;
//    int m_pipeGap;
    class bird* m_bird;
    void clearPipes();
};

#endif // MAP_H
