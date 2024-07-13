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


void viewmodel::onReset()
{
    m_map->bird()->setX(170);
    m_map->bird()->setY(202);
    m_map->bird()->setIsDead(false);
    emit GameUpdated();
}

void viewmodel::onFly()
{


    m_map->bird()->fly();
    emit GameUpdated();

}


void viewmodel::onDrop()
{


    m_map->bird()->drop();
    emit GameUpdated();


}


