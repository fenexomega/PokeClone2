#include "PlayerPhysics.h"

#include "util/Logger.h"

#include "systems/sysPhysics.h"

//TODO hitbox finetuning

PlayerPhysics::PlayerPhysics(int velocity, Rect hitBox, iComponentMediator *mediator)
    : _hitBox(hitBox),_velocity(velocity),cPhysics(mediator)
{
//    _hitBox.w -= _hitBox.w/4;
}

PlayerPhysics::~PlayerPhysics()
{

}

void PlayerPhysics::Update(iGameObject *obj, World *world, float dt)
{
    obj->pos += obj->acc*_velocity;

    //TODO melhorar isso
    obj->rect.x = obj->pos.x - 16;
    obj->rect.y = obj->pos.y ;

    std::vector<Rect> colidables = world->getLayersRect("colidiveis");
    for(auto i : colidables)
    {
        if(sysPhysics::isColliding(obj->rect,i))
        {
            obj->pos -= obj->acc*_velocity;
            obj->rect.x = obj->pos.x - 16;
            obj->rect.y = obj->pos.y ;
            return;
        }
    }

    world->pos = -obj->pos;


}


void PlayerPhysics::receiveMessage(int msg)
{
}

