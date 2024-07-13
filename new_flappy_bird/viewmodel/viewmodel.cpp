#include "viewmodel.h"
#include <QDebug>

viewmodel::viewmodel(QObject *parent, class map* a_map) : QObject(parent), m_map(a_map)
{
    m_map = new map();
}

viewmodel::~viewmodel()
{
    delete m_map;
}

map* viewmodel::getMap() const
{
    return m_map;
}


void viewmodel::onReset()
{
    //reset bird status
    m_map->getBird()->setX(170);
    m_map->getBird()->setY(202);
    m_map->getBird()->setIsDead(false);

    //reset pipes
    m_map->clearPipes();
    m_map->generatePipes();

    //reset best score
    int current_score = m_map->getScoreBoard()->getScore();
    if (current_score > m_map->getScoreBoard()->getBest()) {
        m_map->getScoreBoard()->setBest(current_score);
        emit bestScoreUpdated();
    }

    //reset score
    m_map->getScoreBoard()->resetScore();

    emit birdYChanged();
    emit pipesMoved();
    emit scoreUpdated();
    emit gameOver();
}


void viewmodel::onFly()
{
    if (m_map->getBird()->isDead()) return;
    m_map->getBird()->fly();
    emit birdYChanged();
}

void viewmodel::onDrop()
{
    if (m_map->getBird()->isDead()) return;
    m_map->getBird()->drop();
    emit birdYChanged();
}

void viewmodel::updateBird() {
    if (!m_map->getBird()->isDead()) {
        onDrop();
        if (detectCollision() || m_map->getBird()->getY() <= 0 || m_map->getBird()->getY() >= 448) {
            m_map->getBird()->setIsDead(true);
            qDebug() << "$ " << m_map->getBird()->isDead() << " $";
            emit gameOver();
        }
        else if (detectPass()) {
            m_map->getScoreBoard()->addScore();
            emit scoreUpdated();
        }
    }
}

void viewmodel::updatePipes() {
    if (m_map->getBird()->isDead()) return;
    for (pipe *pipe : m_map->getPipes()) {
        pipe->moveLeft();
    }
    if (m_map->getPipes().first()->getX() < -70) {
//        pipe *firstUpper = m_map->getPipes().takeFirst();
//        pipe *firstLower = m_map->getPipes().takeFirst();
//        delete firstUpper;
//        delete firstLower;
        qDebug() << "remove";
    }

//        int gap = QRandomGenerator::global()->bounded(100, 200);
//        int h_up = QRandomGenerator::global()->bounded(100, 200);
//        int h_down = 448 - h_up - gap;

//        pipe *newUpperPipe = new pipe(m_map->getPipes().last()->getX() + 200, h_up, false);
//        pipe *newLowerPipe = new pipe(m_map->getPipes().last()->getX() + 200, h_down, true);

//        m_map->getPipes().append(newUpperPipe);
//        m_map->getPipes().append(newLowerPipe);
//    }
    emit pipesMoved();
}

void viewmodel::updateGame()
{
    updateBird();
    updatePipes();
}

bool viewmodel::detectCollision() {
    for (pipe *pipe : m_map->getPipes()) {
        if (m_map->getBird()->getX() + 34 > pipe->getX() && m_map->getBird()->getX() < pipe->getX() + 70) {
            if ((!pipe->isUpper() && m_map->getBird()->getY() + 24 > 448 - pipe->getH()) ||
                (pipe->isUpper() && m_map->getBird()->getY() < pipe->getH())) {
                return true;
            }
        }
    }
    return false;
}

bool viewmodel::detectPass() {
    for (pipe *pipe : m_map->getPipes()) {
        if (m_map->getBird()->getX() == pipe->getX() + 70) {
            return true;
        }
    }
    return false;
}
