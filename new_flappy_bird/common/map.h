#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QList>
#include <QRandomGenerator>
#include "bird.h"
#include "pipe.h"

class map : public QObject
{
    Q_OBJECT

public:
    explicit map(QObject *parent = nullptr);
    ~map();

    bird* getBird() const;
    void generatePipes();
    QList<pipe*> getPipes() const;

private:

    const static int pipe_count = 32;
    QList<pipe*> m_pipes;
    bird* m_bird;
};

#endif // MAP_H
