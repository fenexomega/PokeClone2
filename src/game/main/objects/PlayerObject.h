#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "interfaces/iGameObject.h"


#include "game/components/cGraphic.h"
#include "game/components/cInput.h"
#include "game/components/cPhysics.h"
#include "game/components/ComponentMediator.h"

class PlayerObject : public iGameObject
{
private:
    ComponentMediator _mediator;
    cInput *_input;
    cPhysics *_physics;
    cGraphic *_graphic;
    World *_world;

public:
    PlayerObject(cInput *input,cPhysics *physics,cGraphic *graphic,World *world);
    ~PlayerObject();

    // iGameObject interface
    void Update(float dt);
    void Render();
};

#endif // PLAYEROBJECT_H
