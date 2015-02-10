#ifndef DOORPHYSICS_H
#define DOORPHYSICS_H

#include "game/components/cPhysics.h"

class DoorPhysics : public cPhysics
{
private:
    iGameObject *_player;
    Rect _hitBox;
public:
    DoorPhysics(iGameObject *player, iComponentMediator *mediator,Rect hitbox , bool active = true);
    ~DoorPhysics();

    // iComponent interface
    void receiveMessage(int msg);

    // cPhysics interface
    void Update(iGameObject *obj, World *world, float dt);
};

#endif // DOORPHYSICS_H
