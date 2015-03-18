#ifndef DOORPHYSICS_H
#define DOORPHYSICS_H

#include "components/cPhysics.h"

#define DOOR_DISABLE 0x0010

class DoorPhysics : public cPhysics
{
private:
    iGameObject *_player;
    bool _active;

    Map* _map{};
    iGameObject* _obj{};

    void UpdatePos();
public:
    DoorPhysics(iGameObject *player, iComponentMediator *mediator, bool active = true);
    ~DoorPhysics();

    // iComponent interface
    void receiveMessage(int msg);

    // cPhysics interface
    void Update(iGameObject *obj, Map *world, float dt);
};

#endif // DOORPHYSICS_H
