#include "ObjectPhysics.h"

#include "systems/sysPhysics.h"

#include "util/Logger.h"

#define NOT_ACTIVE 0

ObjectPhysics::ObjectPhysics(iGameObject *player, iComponentMediator *mediator, Rect hitbox)
    : cPhysics(mediator),_player(player),_hitBox(hitbox)
{

}

ObjectPhysics::~ObjectPhysics()
{

}


void ObjectPhysics::receiveMessage(int msg)
{
    switch(msg)
    {
        case 1:
        {
            if(sysPhysics::isColliding(_player->rect,_hitBox))
            {
                PRINT("Item pegue!");
            }

        }break;
    }

}

void ObjectPhysics::Update(iGameObject *obj, World *world, float dt)
{
    obj->rect.x = world->pos.x + obj->pos.x + world->offset.x;
    obj->rect.y = world->pos.y + obj->pos.y + world->offset.y;
}
