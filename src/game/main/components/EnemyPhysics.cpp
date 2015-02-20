#include "EnemyPhysics.h"

#include "systems/sysPhysics.h"

#include "util/Logger.h"

#include "game/main/objects/Door.h"

EnemyPhysics::EnemyPhysics(int velocity, Rect hitBox,iGameObject *player, iComponentMediator *mediator)
    : _velocity(velocity),_hitBox(hitBox),cPhysics(mediator),_player(player)

{

}

void EnemyPhysics::Move(Vector2D<int> v)
{
    _obj->pos += v;
    _obj->rect.x = _world->pos.x + _obj->pos.x + _world->offset.x;
    _obj->rect.y = _world->pos.y + _obj->pos.y + _world->offset.y;
    _hitBox.x = _obj->pos.x;
    _hitBox.y = _obj->pos.y;


}

EnemyPhysics::~EnemyPhysics()
{

}



void EnemyPhysics::receiveMessage(int msg)
{

}

void EnemyPhysics::Update(iGameObject *obj, World *world, float dt)
{
    _obj = obj;
    _world = world;
    Move(obj->acc*_velocity);


    std::vector<Rect> colidables = world->getLayersRect("colidiveis");
    //Ver se está colidindo com algum gameObject
    bool colliding = false;
    for(iGameObject *i : world->gameObjects)
        if(sysPhysics::isColliding(obj->rect,i->rect))
        {
            //TODO estão colidindo mas não saem do canto

            //Se for uma porta, você deve colidir
            // senão, pode passar.

            //TODO verificar se a porta está trancada
            if(i->name.compare("door") < 0)
                if( !((Door *) i)->_open )
                colliding = true;
            break;
        }


    for(auto i : colidables)
    {
        if(sysPhysics::isColliding(_hitBox,i)
                || colliding)
        {
            Move(-obj->acc*_velocity);

            break;
        }
    }

}

