#ifndef PLAYERPHYSICS_H
#define PLAYERPHYSICS_H

#include "components/cPhysics.h"

#include "physics/Rect.h"

class PlayerPhysics : public cPhysics
{
private:
    int _velocity = 2;
    Rect _hitBox;
public:
    PlayerPhysics(int velocity, Rect hitBox, ComponentMediator *mediator);
    ~PlayerPhysics();

    // cPhysics interface

    // Component interface
    void receiveMessage(int msg);

    // cPhysics interface
public:
    void Update(iGameObject *obj, Map *world, float dt);
};

#endif // PLAYERPHYSICS_H
