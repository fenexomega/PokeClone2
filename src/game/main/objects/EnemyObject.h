#ifndef ENEMYOBJECT_H
#define ENEMYOBJECT_H


#include "game/components/cInput.h"
#include "game/components/cGraphic.h"
#include "game/components/cPhysics.h"
#include "game/components/ComponentMediator.h"
#include "interfaces/iGameObject.h"

class EnemyObject : public iGameObject
{
private:
    ComponentMediator _mediator;
    cInput *_input;
    cPhysics *_physics;
    cGraphic *_graphic;
    World *_world;
public:
    EnemyObject(cInput *input,cPhysics *physics,cGraphic *graphic,World *world);
    ~EnemyObject();

    // iGameObject interface
    void Update(float dt);
    void Render();
};

#endif // ENEMYOBJECT_H
