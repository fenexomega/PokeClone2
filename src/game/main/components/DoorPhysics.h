#ifndef DOORPHYSICS_H
#define DOORPHYSICS_H

#include "game/components/cPhysics.h"

#define DOOR_DISABLE 3

class DoorPhysics : public cPhysics
{
private:
    iGameObject *_player;
    bool _active;
public:
    DoorPhysics(iGameObject *player, iComponentMediator *mediator, bool active = true);
    ~DoorPhysics();

    // iComponent interface
    void receiveMessage(int msg);

    // cPhysics interface
    void Update(iGameObject *obj, Map *world, float dt);
};

#endif // DOORPHYSICS_H
