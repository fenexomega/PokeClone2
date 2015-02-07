#ifndef CPHYSICS
#define CPHYSICS

#include "interfaces/iGameObject.h"
#include "game/main/objects/World.h"
#include "interfaces/iComponent.h"

class cPhysics : public iComponent
{
public:
    cPhysics(iComponentMediator *mediator)
        : iComponent(mediator){}
    virtual void Update(iGameObject *obj,World *world,float dt) {}
};

#endif // CPHYSICS

