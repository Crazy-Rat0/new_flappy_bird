#include "map.h"

map::map(QObject *parent)
    : QObject(parent)
{
    m_bird = new bird();
    generatePipes();
    m_scoreboard = new scoreboard();
}

map::~map() {
    delete m_bird;
    m_pipes.clear();
}

bird* map::getBird() const {
    return m_bird;
}

QList<pipe*> map::getPipes() const {
    return m_pipes;
}

scoreboard* map::getScoreBoard() const{
    return m_scoreboard;
}

void map::generatePipes() {
    for (int i = 0; i < pipe_count; i++) {
        int gap = QRandomGenerator::global()->bounded(100, 200);
        int h_up = QRandomGenerator::global()->bounded(100, 200);
        int h_down = 448 - h_up - gap;

        pipe *upperPipe = new pipe(i * 200 + 300, h_up, true);
        pipe *lowerPipe = new pipe(i * 200 + 300, h_down, false);

        m_pipes.append(upperPipe);
        m_pipes.append(lowerPipe);
    }
}

void map::clearPipes()
{
    qDeleteAll(m_pipes);
    m_pipes.clear();
}
