#ifndef PLAYERPHYSICS_H
#define PLAYERPHYSICS_H

#include "game/components/cPhysics.h"
#include "components/MessageSender.h"
#include "physics/Rect.h"

class PlayerPhysics : public cPhysics
{
private:
    Rect _hitBox;
    int _velocity = 2;
public:
    PlayerPhysics(int velocity,Rect hitBox,
                  iComponentMediator *mediator);
    ~PlayerPhysics();

    // cPhysics interface
    void Update(iGameObject *obj, World *world, float dt);

    // Component interface
    void receiveMessage(int msg);

};

#endif // PLAYERPHYSICS_H
