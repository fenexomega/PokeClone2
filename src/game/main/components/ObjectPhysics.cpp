#include "ObjectPhysics.h"

#include "systems/sysPhysics.h"

#include "util/Logger.h"

#include "game/main/objects/Key.h"

#define PLAYER_INTERACTION 1
#define DISSAPEAR 2

ObjectPhysics::ObjectPhysics(iGameObject *player, iComponentMediator *mediator, bool active)
    : cPhysics(mediator),_player(player),_active(active)
{

}

ObjectPhysics::~ObjectPhysics()
{

}


void ObjectPhysics::receiveMessage(int msg)
{
    switch(msg)
    {
        case PLAYER_INTERACTION:
        {
        if(_active)
            if(sysPhysics::isColliding(_player->rect,_obj->rect))
            {
                PRINT("Item pegue!");
                _active = false;
                sendMessage(DISSAPEAR);

              Key*key =  ((Key *) _obj);
              key->Notify(key);
            }

        }break;
    }

}

void ObjectPhysics::Update(iGameObject *obj, World *world, float dt)
{
    _obj = obj;
    obj->rect.x = world->pos.x + obj->pos.x + world->offset.x;
    obj->rect.y = world->pos.y + obj->pos.y + world->offset.y;
}
