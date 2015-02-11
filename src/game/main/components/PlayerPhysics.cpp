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

void PlayerPhysics::Move(Vector2D<int> v)
{
    _obj->pos += v;

    //TODO melhorar isso
    //o vetor POS dá a posição exata no MEIO
    _hitBox.x = _obj->pos.x - 16;
    _hitBox.y = _obj->pos.y;
    //O Mundo deveria se mexer de forma independente?
    _world->pos = -_obj->pos;

}


void PlayerPhysics::Update(iGameObject *obj, World *world, float dt)
{

    _obj = obj;
    _world = world;
    Move(obj->acc*_velocity);

    std::vector<Rect> colidables = world->getLayersRect("colidiveis");
    for(auto i : colidables)
    {
        if(sysPhysics::isColliding(_hitBox,i))
        {
            Move(-_obj->acc*_velocity);
            return;
        }
    }
}


void PlayerPhysics::receiveMessage(int msg)
{

    if(msg == MOVE_BACK)
    {
        //Observer Notify?
        Move(-_obj->acc*_velocity);
    }
}

