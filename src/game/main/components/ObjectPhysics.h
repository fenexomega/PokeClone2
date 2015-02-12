#ifndef OBJECTPHYSICS_H
#define OBJECTPHYSICS_H

#include "game/components/cPhysics.h"

class ObjectPhysics : public cPhysics
{
private:
    iGameObject *_player;
    bool _active;
    iGameObject *_obj;
public:
    ObjectPhysics(iGameObject *player,iComponentMediator *mediator,bool active = true);
    ~ObjectPhysics();

    // iComponent interface
    void receiveMessage(int msg);

    // cPhysics interface
    void Update(iGameObject *obj, World *world, float dt);
};

#endif // OBJECTPHYSICS_H
