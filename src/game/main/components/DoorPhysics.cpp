#include "DoorPhysics.h"

#include "systems/sysPhysics.h"

#include "util/Logger.h"

#include "main/components/PlayerPhysics.h"

void DoorPhysics::UpdatePos()
{
    _obj->rect.x = _map->pos.x + _obj->pos.x + _map->offset.x;
    _obj->rect.y = _map->pos.y + _obj->pos.y + _map->offset.y;
}

DoorPhysics::DoorPhysics(iGameObject *player, iComponentMediator *mediator, bool active)
    : cPhysics(mediator),_player(player),_active(active)
{

}

DoorPhysics::~DoorPhysics()
{

}



void DoorPhysics::receiveMessage(int msg)
{
    switch(msg)
    {
    case DOOR_DISABLE:
        LOG("Porta Desativada");
        _active = false;
        sendMessage(DISSAPEAR);
        break;
    case OBJS_UPDATE_POS:
        UpdatePos();
        break;
    }

}

void DoorPhysics::Update(iGameObject *obj, Map *world, float dt)
{

//NOTE: deveria rever a ordem das movimentações
    if(!_obj) _obj = obj;
    if(!_map) _map = world;
   UpdatePos();

    if(_active && sysPhysics::isColliding(_player->rect,obj->rect))
    {
        _player->SendMessage(MOVE_BACK);
        _map->sendMessage(OBJS_UPDATE_POS);
    }

}
