#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include "physics/Rect.h"
#include "math/Vector2D.h"
#include "interfaces/iGameObject.h"

#include "game/components/cGraphic.h"
#include "game/components/cInput.h"
#include "game/components/cPhysics.h"
#include "game/components/ComponentMediator.h"

#include "game/objects/World.h"

class GameObject : public iGameObject
{
public:
    GameObject(cInput *input,cPhysics *physics,cGraphic *graphic,World *world);
    ~GameObject();

    ComponentMediator mediator;

    cInput *_input;
    cPhysics *_physics;
    cGraphic *_graphic;

    World *_world;

    virtual void Update(float dt);

    virtual void Render();

};

#endif // GAMEOBJECT_H
