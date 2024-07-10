#include "map.h"

map::map(QObject *parent)
    : QObject(parent), /*m_pipeCount(10),*/ /*m_pipeGap(150),*/ m_bird(new class bird(this))
{
//    generatePipes();
}

map::~map()
{
//    clearPipes();
    delete m_bird;
}

//void Map::generatePipes()
//{
//    clearPipes();
//    for (int i = 0; i < m_pipeCount; ++i) {
//        int h_up = QRandomGenerator::global()->bounded(100, 200);
//        int h_down = 448 - h_up - m_pipeGap;

//        Pipe *upperPipe = new Pipe(nullptr, i * 200 + 300, h_up, false);
//        Pipe *lowerPipe = new Pipe(nullptr, i * 200 + 300, h_down, true);

//        m_pipes.append(upperPipe);
//        m_pipes.append(lowerPipe);
//    }
//    emit pipesUpdated();
//}

//void Map::movePipes()
//{
//    for (Pipe *pipe : qAsConst(m_pipes)) {
//        pipe->setX(pipe->x() - 4);
//    }

//    if (m_pipes.first()->x() < -70) {
//        Pipe *firstUpper = m_pipes.takeFirst();
//        Pipe *firstLower = m_pipes.takeFirst();
//        delete firstUpper;
//        delete firstLower;

//        int h_up = QRandomGenerator::global()->bounded(100, 200);
//        int h_down = 448 - h_up - m_pipeGap;

//        Pipe *newUpperPipe = new Pipe(nullptr, m_pipes.last()->x() + 200, h_up, false);
//        Pipe *newLowerPipe = new Pipe(nullptr, m_pipes.last()->x() + 200, h_down, true);

//        m_pipes.append(newUpperPipe);
//        m_pipes.append(newLowerPipe);
//    }
//    emit pipesUpdated();
//}

void map::updateBird()
{
    if (!m_bird->isDead()) {
        m_bird->drop();
//        if (checkCollision() || m_bird->y() <= 0 || m_bird->y() >= 448) {
//            m_bird->setIsDead(true);
//            emit collisionDetected();
//        }
    }
}

//bool Map::checkCollision()
//{
//    for (Pipe *pipe : qAsConst(m_pipes)) {
//        if (m_bird->x() + 34 > pipe->x() && m_bird->x() < pipe->x() + 70) {
//            if ((pipe->isBottom() && m_bird->y() + 24 > 448 - pipe->height()) ||
//                (!pipe->isBottom() && m_bird->y() < pipe->height())) {
//                emit collisionDetected();
//                return true;
//            }
//        }
//    }
//    return false;
//}

bird* map::bird() const
{
    return m_bird;
}

//const QList<Pipe*>& Map::pipes() const
//{
//    return m_pipes;
//}

//void Map::clearPipes()
//{
//    qDeleteAll(m_pipes);
//    m_pipes.clear();
//}
