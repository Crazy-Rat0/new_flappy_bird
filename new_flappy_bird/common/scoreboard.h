#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QObject>

class scoreboard : QObject
{
    Q_OBJECT

public:
    scoreboard();

    int getScore();
    void addScore();
    void resetScore();

    int getBest();
    void setBest(int best_score);

private:
    int score;
    int best;
};

#endif // SCOREBOARD_H
