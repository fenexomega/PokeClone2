#ifndef CPHYSICS
#define CPHYSICS

#include "interfaces/iGameObject.h"
#include "game/objects/World.h"

class cPhysics
{
public:
    virtual void Update(iGameObject *obj,World *world,float dt) = 0;
};

#endif // CPHYSICS

