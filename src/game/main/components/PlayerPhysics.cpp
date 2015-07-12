#include "PlayerPhysics.h"

#include "util/Logger.h"

#include "systems/sysPhysics.h"

PlayerPhysics::PlayerPhysics(int velocity,Rect hitBox, ComponentMediator* mediator)
    : _velocity(velocity),_hitBox(hitBox), cPhysics(mediator)
{
}

PlayerPhysics::~PlayerPhysics()
{

}

void PlayerPhysics::Update(iGameObject *obj, Map *world, float dt)
{

    Vector2D finalVelocity = obj->acc*(_velocity*dt);

    obj->pos += finalVelocity;
#ifndef RELEASE
    PRINT(obj->pos);
    PRINT(obj->acc);
    PRINT(_velocity*dt);
    PRINT(_hitBox);
#endif
    _hitBox.x = obj->pos.x - 16;
    _hitBox.y = obj->pos.y;

    std::vector<Rect> colidables = world->getLayersRect("colidiveis");
    for(auto i : colidables)
    {
        if(sysPhysics::isColliding(_hitBox,i))
        {
            obj->pos -= finalVelocity;
            return;
        }
    }
    world->pos = -obj->pos.floor();
}


void PlayerPhysics::receiveMessage(int msg)
{
}


