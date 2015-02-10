#include "EnemyPhysics.h"

#include "systems/sysPhysics.h"

#include "util/Logger.h"

EnemyPhysics::EnemyPhysics(int velocity, Rect hitBox,iGameObject *player, iComponentMediator *mediator)
    : _velocity(velocity),_hitBox(hitBox),cPhysics(mediator),_player(player)

{

}

EnemyPhysics::~EnemyPhysics()
{

}



void EnemyPhysics::receiveMessage(int msg)
{
}

void EnemyPhysics::Update(iGameObject *obj, World *world, float dt)
{

    obj->pos += obj->acc*_velocity;

    _hitBox.x = obj->pos.x;
    _hitBox.y = obj->pos.y + 16;

    std::vector<Rect> colidables = world->getLayersRect("colidiveis");
    //Ver se está colidindo com algum gameObject
    bool colliding = false;
    for(iGameObject *i : world->gameObjects)
        if(sysPhysics::isColliding(obj->rect,i->rect))
        {
            //TODO estão colidindo mas não saem do canto
            PRINT("FODA_SE");
            colliding = true;
            break;
        }


    for(auto i : colidables)
    {
        if(sysPhysics::isColliding(_hitBox,i) || sysPhysics::isColliding(_player->rect,_hitBox)
                || colliding)
        {
            obj->pos -= obj->acc*_velocity;
            break;
        }
    }
    obj->rect.x = world->pos.x + obj->pos.x + world->offset.x;
    obj->rect.y = world->pos.y + obj->pos.y + world->offset.y;
}

