#include "viewmodel.h"
#include "QDebug"

viewmodel::viewmodel(QObject *parent,class map* a_map) : QObject(parent), m_map(a_map)
{
    //connect(m_map, &map::collisionDetected, this, &viewmodel::gameOver);
    m_map =new class map;
}

viewmodel::~viewmodel()
{
    //delete m_map;
}

map* viewmodel::map() const
{
    return m_map;
}

void viewmodel::updateGame()
{
    m_map->updateBird();
    // 检查碰撞
    // if (m_map->checkCollision()) {
    //     emit gameOver();
    // }
    emit gameUpdated();
}
void viewmodel::onReset()
{
    m_map->bird()->setX(170);
    m_map->bird()->setY(202);
    m_map->bird()->setIsDead(false);
    emit birdYChanged();
}

void viewmodel::onFly()
{


    m_map->bird()->fly();
    emit birdYChanged();

}


void viewmodel::onDrop()
{


    m_map->bird()->drop();
    emit birdYChanged();


}


