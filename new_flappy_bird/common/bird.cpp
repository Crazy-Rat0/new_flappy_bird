#include "bird.h"

bird::bird(QObject *parent)
    : QObject(parent), m_isDead(false), m_x(0), m_y(0)
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
    setY(y() + 1);
}

void bird::fly()
{
    if (!isDead()) {
        setY(y() - 10);
    }
}

void bird::changeImage()
{
    // Change bird image logic
}
