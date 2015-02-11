#include "DoorPhysics.h"

#include "systems/sysPhysics.h"

#include "util/Logger.h"

#include "game/main/components/PlayerPhysics.h"

DoorPhysics::DoorPhysics(iGameObject *player, iComponentMediator *mediator, Rect hitbox, bool active)
    : cPhysics(mediator),_hitBox(hitbox),_player(player),_active(active)
{

}

DoorPhysics::~DoorPhysics()
{

}



void DoorPhysics::receiveMessage(int msg)
{
    if(msg == DOOR_DISABLE)
    {
        _active = false;
    }
}

void DoorPhysics::Update(iGameObject *obj, World *world, float dt)
{

//TODO deveria rever a ordem das movimentações
    obj->rect.x = world->pos.x + obj->pos.x + world->offset.x;
    obj->rect.y = world->pos.y + obj->pos.y + world->offset.y;
    if(_active)
    if(sysPhysics::isColliding(_player->rect,obj->rect))
    {
        _player->SendMessage(MOVE_BACK);
        obj->rect.x = world->pos.x + obj->pos.x + world->offset.x;
        obj->rect.y = world->pos.y + obj->pos.y + world->offset.y;
    }

}
