#ifndef MONSTR_H
#define MONSTR_H
#include "creature.h"

class Monstr : public Creature
{
public:
    Monstr();
    Monstr(QPoint place, int lives = 1){place_ = place;endPlace_ = place;lives_ = lives;};
    Monstr(QPoint place, QPoint endPlace, int lives = 1){place_ = place; endPlace_ = endPlace; lives_ = lives;};
    void shoted() override;
};

#endif // MONSTR_H
