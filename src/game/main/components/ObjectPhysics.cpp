#include "ObjectPhysics.h"

#include "systems/sysPhysics.h"
#include "util/Logger.h"
#include "main/objects/IteractiveItem.h"


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
        if(_active && sysPhysics::isColliding(_player->rect,_obj->rect))
        {
            LOG("Item pegue!");
            _active = false;
            sendMessage(DISSAPEAR);

            IteractiveItem *key = dynamic_cast<IteractiveItem *>(_obj);

            if(key == nullptr)
                throw std::runtime_error("Object " + _obj->name + " is not a Key" );

            key->Notify(key);
        }
        break;
     case OBJS_UPDATE_POS:
        UpdatePos();
        break;

    }

}

void ObjectPhysics::Update(iGameObject *obj, Map *world, float dt)
{
    _obj = obj;
    _map = world;
    UpdatePos();

}

void ObjectPhysics::UpdatePos()
{
    _obj->rect.x = _map->pos.x + _obj->pos.x + _map->offset.x;
    _obj->rect.y = _map->pos.y + _obj->pos.y + _map->offset.y;
}
