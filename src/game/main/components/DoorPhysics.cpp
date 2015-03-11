#include "DoorPhysics.h"

#include "systems/sysPhysics.h"

#include "util/Logger.h"

#include "main/components/PlayerPhysics.h"

DoorPhysics::DoorPhysics(iGameObject *player, iComponentMediator *mediator, bool active)
    : cPhysics(mediator),_player(player),_active(active)
{

}

DoorPhysics::~DoorPhysics()
{

}



void DoorPhysics::receiveMessage(int msg)
{
    if(msg == DOOR_DISABLE)
    {
        LOG("Porta Desativada");
        _active = false;
    }
}

void DoorPhysics::Update(iGameObject *obj, Map *world, float dt)
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
