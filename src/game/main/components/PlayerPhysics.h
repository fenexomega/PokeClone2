#ifndef PLAYERPHYSICS_H
#define PLAYERPHYSICS_H

#include "game/components/cPhysics.h"

#include "physics/Rect.h"

class PlayerPhysics : public cPhysics
{
private:
    int _velocity = 2;
    Rect _hitBox;
public:
    PlayerPhysics(int velocity,Rect hitBox);
    ~PlayerPhysics();

    // cPhysics interface
    void Update(iGameObject *obj, World *world, float dt);

    // Component interface
    void receiveMessage(int msg);
};

#endif // PLAYERPHYSICS_H
