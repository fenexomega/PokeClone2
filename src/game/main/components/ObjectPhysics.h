#ifndef OBJECTPHYSICS_H
#define OBJECTPHYSICS_H

#include "components/cPhysics.h"

class ObjectPhysics : public cPhysics
{
private:
    iGameObject *_player{};
    bool _active;
    iGameObject *_obj{};
    Map *_map{};
public:
    ObjectPhysics(iGameObject *player,iComponentMediator *mediator,bool active = true);
    ~ObjectPhysics();

    // iComponent interface
    void receiveMessage(int msg);

    // cPhysics interface
    void Update(iGameObject *obj, Map *world, float dt);
    void UpdatePos();
};

#endif // OBJECTPHYSICS_H
