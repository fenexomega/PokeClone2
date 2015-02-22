#include "TeleporterPhysics.h"

#include "systems/sysPhysics.h"

#include "io/FileLoader.h"

#include "util/Logger.h"

TeleporterPhysics::TeleporterPhysics(iComponentMediator *mediator, iGameObject *player,
                                     WorldContext *wc, std::string newMap, Vector2D<int> mapPos)
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
        LOG("TELEPORTOU");
        break;
    }
}

void TeleporterPhysics::Update(iGameObject *obj, World *world, float dt)
{
//    LOG("TELEPORTER");
    obj->rect.x = world->pos.x + obj->pos.x + world->offset.x;
    obj->rect.y = world->pos.y + obj->pos.y + world->offset.y;
    if(sysPhysics::isColliding(obj->rect,_player->rect))
    {
        sendMessage(PLAYER_NEAR);
    }
}
