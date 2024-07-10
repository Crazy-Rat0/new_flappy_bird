#ifndef BIRD_H
#define BIRD_H

#include <QObject>

class bird : public QObject
{
    Q_OBJECT
public:
    explicit bird(QObject *parent = nullptr);

    bool isDead() const;
    void setIsDead(bool isDead);

    int x() const;
    void setX(int x);

    int y() const;
    void setY(int y);

signals:
    void isDeadChanged();
    void xChanged();
    void yChanged();

public slots:
    void drop();
    void fly();
    void changeImage();

private:
    bool m_isDead;
    int m_x;
    int m_y;
};

#endif // BIRD_H
