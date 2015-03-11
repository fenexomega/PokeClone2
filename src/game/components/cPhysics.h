#ifndef CPHYSICS
#define CPHYSICS

#include "interfaces/iGameObject.h"
#include "main/objects/Map.h"
#include "interfaces/iComponent.h"

class cPhysics : public iComponent
{
public:
    cPhysics(iComponentMediator *mediator)
        : iComponent(mediator){}
    virtual void Update(iGameObject *obj,Map *world,float dt) {}
};

#endif // CPHYSICS

