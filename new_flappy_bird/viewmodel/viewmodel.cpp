#include "viewmodel.h"
#include "QDebug"

viewmodel::viewmodel(QObject *parent,class map* a_map) : QObject(parent), m_map(a_map)
{
    //connect(m_map, &map::collisionDetected, this, &viewmodel::gameOver);
}

viewmodel::~viewmodel()
{
    //delete m_map;
}

//map* viewmodel::map() const
//{
//    return m_map;
//}

void viewmodel::updateGame()
{
    m_map->updateBird();
    // 检查碰撞
    // if (m_map->checkCollision()) {
    //     emit gameOver();
    // }
    emit gameUpdated();
}

void viewmodel::onFly()
{
    qDebug()<<"access to fly successfully #"<<11;
    qDebug()<<m_map->bird()->y();
    m_map->bird()->fly();
    qDebug()<<"access to fly total successfully";
    emit birdYChanged();
    emit birdY2Changed();//debug 用，记得删除
}
