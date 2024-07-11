#include "bird.h"
#include <QDebug>
bird::bird(QObject *parent)
    : QObject(parent), m_isDead(false), m_x(170), m_y(202)
{
}

bool bird::isDead() const
{
    return m_isDead;
}

void bird::setIsDead(bool isDead)
{
    if (m_isDead != isDead) {
        m_isDead = isDead;
        emit isDeadChanged();
    }
}

int bird::x() const
{
    return m_x;
}

void bird::setX(int x)
{
    if (m_x != x) {
        m_x = x;
        emit xChanged();
    }
}

int bird::y() const
{
    return m_y;
}

void bird::setY(int y)
{
    if (m_y != y) {
        m_y = y;
        emit yChanged();
    }
}

void bird::drop()
{
    if (!isDead()) {

        if(y()+2<=401)
        {
            setY(y()+2);
        }

        else
        {
            setY(401);
            setIsDead(true);
        }

    }


}

void bird::fly()
{

    if (!isDead()) {
        qDebug()<<"fly successfully now Y:";
        if(y()-40>=0)
        setY(y() - 40);
        else
            setY(0);
        qDebug()<<y();
    }

}

void bird::changeImage()
{
    // Change bird image logic
}
