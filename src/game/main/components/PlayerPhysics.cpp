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

    obj->pos += obj->acc*_velocity;

    _hitBox.x = obj->pos.x;
    _hitBox.y = obj->pos.y + 16;

    std::vector<Rect> colidables = world->getLayersRect("colidiveis");
    for(auto i : colidables)
    {
        if(sysPhysics::isColliding(_hitBox,i))
        {
            obj->pos -= obj->acc*_velocity;
            return;
        }
    }
    world->pos = -obj->pos;
}


void PlayerPhysics::receiveMessage(int msg)
{
}


