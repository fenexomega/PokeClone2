#ifndef OBJECTPHYSICS_H
#define OBJECTPHYSICS_H

#include "game/components/cPhysics.h"

class ObjectPhysics : public cPhysics
{
private:
    iGameObject *_player;
    Rect _hitBox;
public:
    ObjectPhysics(iGameObject *player,iComponentMediator *mediator,Rect hitbox);
    ~ObjectPhysics();

    // iComponent interface
    void receiveMessage(int msg);

    // cPhysics interface
    void Update(iGameObject *obj, World *world, float dt);
};

#endif // OBJECTPHYSICS_H
