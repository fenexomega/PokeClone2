#include "DoorPhysics.h"

#include "systems/sysPhysics.h"

#include "util/Logger.h"

#include "game/main/components/PlayerPhysics.h"

DoorPhysics::DoorPhysics(iGameObject *player, iComponentMediator *mediator, Rect hitbox, bool active)
    : cPhysics(mediator),_hitBox(hitbox),_player(player)
{

}

DoorPhysics::~DoorPhysics()
{

}



void DoorPhysics::receiveMessage(int msg)
{
}

void DoorPhysics::Update(iGameObject *obj, World *world, float dt)
{
    if(sysPhysics::isColliding(_player->rect,_hitBox))
    {
        _player->SendMessage(PLAYER_MOVE_BACK);
        return;
    }
    obj->rect.x = world->pos.x + obj->pos.x + world->offset.x;
    obj->rect.y = world->pos.y + obj->pos.y + world->offset.y;

}
