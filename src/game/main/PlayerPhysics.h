#ifndef PLAYERPHYSICS_H
#define PLAYERPHYSICS_H

#include "game/components/cPhysics.h"

class PlayerPhysics : public cPhysics
{
private:
    int velocity = 2;
    Rect *hitBox;
public:
    PlayerPhysics(int _velocity);
    ~PlayerPhysics();

    // cPhysics interface
    void Update(iGameObject *obj, World *world, float dt);

    // Component interface
    void receiveMessage(int msg);
};

#endif // PLAYERPHYSICS_H
