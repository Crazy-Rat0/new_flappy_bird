//#include "viewmodel.h"


////viewmodel::viewmodel(QObject *parent) : QObject(parent), m_map(new map(this))
////{
////    connect(m_map, &map::collisionDetected, this, &viewmodel::gameOver);
////}

////viewmodel::~viewmodel()
////{
////    delete m_map;
////}

//map* viewmodel::map() const
//{
//    return m_map;
//}

//void viewmodel::updateGame()
//{
//    m_map->updateBird();
//    // 检查碰撞
//    // if (m_map->checkCollision()) {
//    //     emit gameOver();
//    // }
//    emit gameUpdated();
//}

//void viewmodel::onFly()
//{
//    m_map->bird()->fly();
//}
