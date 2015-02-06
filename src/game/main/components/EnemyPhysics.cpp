#include "EnemyPhysics.h"

#include "systems/sysPhysics.h"

#include "util/Logger.h"

EnemyPhysics::EnemyPhysics(int velocity,Rect hitBox)
    : _velocity(velocity),_hitBox(hitBox)

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
    for(auto i : colidables)
    {
        if(sysPhysics::isColliding(_hitBox,i))
        {
            obj->pos -= obj->acc*_velocity;
            break;
        }
    }
    obj->rect.x = world->pos.x + obj->pos.x + world->offset.x;
    obj->rect.y = world->pos.y + obj->pos.y + world->offset.y;
}

