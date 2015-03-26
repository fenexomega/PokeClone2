#include "TeleporterPhysics.h"

#include "systems/sysPhysics.h"
#include "io/FileLoader.h"
#include "util/Logger.h"

#include "main/objects/World.h"

#include "Factory.h"
#include "main/objects/GameObject.h"

TeleporterPhysics::TeleporterPhysics(iComponentMediator *mediator, iGameObject *player,
                                     World *wc)
    : cPhysics(mediator),_player(player),_wc(wc)
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
        LOG("TELEPORTOU PARA " + _mapName + " [" + TOSTR(_mapPos.x)
            + ", " + TOSTR(_mapPos.y) + "]");

        _wc->setActualMap(_mapName,_mapPos);

        break;
    }
}

void TeleporterPhysics::Update(iGameObject *obj,
                               Map *world, float dt)
{
    obj->rect.x = world->pos.x + obj->pos.x + world->offset.x;
    obj->rect.y = world->pos.y + obj->pos.y + world->offset.y;
    if(sysPhysics::isColliding(obj->rect,_player->rect))
    {
        sendMessage(PLAYER_NEAR);
    }
}

void TeleporterPhysics::setMapToTeleport(
        const std::string mapName,
        const Vector2D mapPos)
{
    _mapName = mapName;
    _mapPos = mapPos;
}
