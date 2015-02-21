#ifndef TELEPORTERPHYSICS_H
#define TELEPORTERPHYSICS_H

#include "game/components/cPhysics.h"

class TeleporterPhysics : public cPhysics
{
public:
    TeleporterPhysics(iComponentMediator *mediator);
    ~TeleporterPhysics();

    // iComponent interface
    void receiveMessage(int msg);

    // cPhysics interface
    void Update(iGameObject *obj, World *world, float dt);
};

#endif // TELEPORTERPHYSICS_H
