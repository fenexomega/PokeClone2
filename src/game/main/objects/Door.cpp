#include "Door.h"

#include "io/FileLoader.h"
#include "main/objects/GameObject.h"

#include "main/components/DoorPhysics.h"
#include "main/components/ScriptedInput.h"
#include "main/components/DecorationGraphic.h"

Door::Door(Map *world)
    : _open(false),GameObject(world)
{

}
std::string Door::keyName() const
{
    return _keyName;
}

void Door::setKeyName(const std::string &keyName)
{
    _keyName = keyName;
}


Door::~Door()
{

}

Door *Door::createDoor(Map *world, std::string JsonFile, iGameObject *player)
{
    Json::Value json = FileLoader::LoadJson(JsonFile);
    Door *door = new Door(world);
    iComponentMediator *mediator = door->mediator();
    door->name = json["name"].asString();
    door->type = json["type"].asString();

    door->setComponents( new ScriptedInput(json["script"].asString(),mediator,player),
            new DoorPhysics(player,mediator),
            new DecorationGraphic(json["image"].asString(),mediator));

    door->_keyName = json["key"].asString();

    return door;

}



void Door::Receive(void *MSG)
{
    _open = true;
    SendMessage(DOOR_DISABLE);
}
