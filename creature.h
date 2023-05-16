#ifndef CREATURE_H
#define CREATURE_H
#include <QPoint>

class Creature
{
public:
    Creature();
    void setPlace(QPoint place){place_ = place;};
    void setEndPlace(QPoint place){endPlace_ = place;};
    void setLives(int lives){lives_ = lives;};
    QPoint getPlace() const{return place_;};
    QPoint getEndPlace() const{return endPlace_;};
    int getLives() const{return lives_;};
    virtual void shoted() = 0;
protected:
    QPoint place_;
    QPoint endPlace_;
    int lives_;
};

#endif // CREATURE_H
