#ifndef CPHYSICS
#define CPHYSICS

#include "interfaces/iGameObject.h"
#include "game/objects/World.h"
#include "game/components/Component.h"

class cPhysics : public Component
{
public:
    virtual void Update(iGameObject *obj,World *world,float dt) = 0;
};

#endif // CPHYSICS

