#ifndef PIPE_H
#define PIPE_H

#include <QObject>

class pipe : QObject
{
    Q_OBJECT

public:
    pipe(int x, int h, bool is_upper, QObject *parent = nullptr);

    int getX() const;
    void setX(int x);

    int getH() const;
    int isUpper() const;

    void moveLeft();

private:
    int m_x;
    const int m_h;
    const bool is_upper;  // true表示上，false表示下
};

#endif // PIPE_H
