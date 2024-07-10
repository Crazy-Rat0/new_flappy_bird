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
    class bird* m_bird;
//    int m_pipeCount;
//    int m_pipeGap;

    void clearPipes();
};

#endif // MAP_H
