#ifndef PLAYER_H
#define PLAYER_H
#include "creature.h"

class Player: public Creature
{
public:
    Player();
    void shoted() override;
};

#endif // PLAYER_H
