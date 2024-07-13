#include "bird.h"

bird::bird(QObject *parent)
    : QObject(parent), m_isDead(false), m_x(170), m_y(202) {}

bool bird::isDead() const
{
    return m_isDead;
}

void bird::setIsDead(bool isDead)
{
    m_isDead = isDead;
}

int bird::getX() const
{
    return m_x;
}

void bird::setX(int x)
{
    m_x = x;
}

int bird::getY() const
{
    return m_y;
}

void bird::setY(int y)
{
    m_y = y;
}

void bird::drop()
{
    setY(getY() + 2);
}

void bird::fly()
{
    if(getY() - 40 >= 0) {
        setY(getY() - 40);
    }
    else {
        setY(0);
    }
}

void bird::changeImage()
{
    // Change bird image logic
}
