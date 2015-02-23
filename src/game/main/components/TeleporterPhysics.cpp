#include "TeleporterPhysics.h"

#include "systems/sysPhysics.h"
#include "io/FileLoader.h"
#include "util/Logger.h"

#include "game/main/objects/World.h"

#include "game/Factory.h"
#include "game/main/objects/GameObject.h"


TeleporterPhysics::TeleporterPhysics(iComponentMediator *mediator, iGameObject *player,
                                     World *wc, std::string newMap, Vector2D<int> mapPos)
    : cPhysics(mediator),_player(player),_wc(wc),_map(newMap),_mapPos(mapPos)
{

}

TeleporterPhysics::~TeleporterPhysics()
{

}



void TeleporterPhysics::receiveMessage(int msg)
{
    switch(msg)
    {
    case CHANGE_MAP:
        //TELEPORT CODE
        LOG("TELEPORTOU PARA " + _map);
        Map *world = Factory::createWorld(_map);
        //TODO BUG implementar melhor esse teleporte
        world->pos = -_mapPos ;
        //TODO map ou world deveriam guardar o player?
        _wc->setWorld(world);
        _player->pos = _mapPos;
        ((GameObject *)_player)->_world = world;


        break;
    }
}

void TeleporterPhysics::Update(iGameObject *obj, Map *world, float dt)
{
//    LOG("TELEPORTER");
    obj->rect.x = world->pos.x + obj->pos.x + world->offset.x;
    obj->rect.y = world->pos.y + obj->pos.y + world->offset.y;
    if(sysPhysics::isColliding(obj->rect,_player->rect))
    {
        sendMessage(PLAYER_NEAR);
    }
}
