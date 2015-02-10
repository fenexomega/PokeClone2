#include "PlayerPhysics.h"

#include "util/Logger.h"

#include "systems/sysPhysics.h"

//TODO hitbox finetuning

void PlayerPhysics::Move(Vector2D<int> v)
{
    _obj->pos += v;

    //TODO melhorar isso
    _obj->rect.x = _obj->pos.x -16;
    _obj->rect.y = _obj->pos.y;
    _world->pos = -_obj->pos;

}

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
    _obj = obj;
    _world = world;
    Move(obj->acc*_velocity);



    std::vector<Rect> colidables = world->getLayersRect("colidiveis");
    for(auto i : colidables)
    {
        if(sysPhysics::isColliding(obj->rect,i))
        {
            Move(-obj->acc*_velocity);
            return;
        }
    }



}


void PlayerPhysics::receiveMessage(int msg)
{
    if(msg == PLAYER_MOVE_BACK)
    {
        Move(-_obj->acc*_velocity);
    }
}

