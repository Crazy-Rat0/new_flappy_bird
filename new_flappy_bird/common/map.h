#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QList>
#include <QRandomGenerator>
#include "bird.h"
#include "pipe.h"
#include "scoreboard.h"

class map : public QObject
{
    Q_OBJECT

public:
    explicit map(QObject *parent = nullptr);
    ~map();

    bird* getBird() const;
    QList<pipe*> getPipes() const;
    scoreboard* getScoreBoard() const;

    void generatePipes();
    void clearPipes();

private:
    const static int pipe_count = 32;
    QList<pipe*> m_pipes;
    bird* m_bird;
    scoreboard* m_scoreboard;
};

#endif // MAP_H
