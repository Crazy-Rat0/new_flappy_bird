#include "pipe.h"

pipe::pipe(int x, int h, bool is_upper, QObject *parent)
    : QObject(parent), m_x(x), m_h(h), is_upper(is_upper) {}

int pipe::getX() const {
    return m_x;
}

void pipe::setX(int x) {
    m_x = x;
}

int pipe::getH() const {
    return m_h;
}

int pipe::isUpper() const {
    return is_upper;
}

void pipe::moveLeft() {
    setX(getX() - 1.5);
}
