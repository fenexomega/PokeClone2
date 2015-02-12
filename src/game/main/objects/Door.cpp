#include "Door.h"

#include "io/FileLoader.h"
#include "game/main/objects/GameObject.h"

#include "game/main/components/DoorPhysics.h"
#include "game/main/components/ScriptedInput.h"
#include "game/main/components/DecorationGraphic.h"

Door::Door(World *world)
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

Door *Door::createDoor(World *world, std::string JsonFile, iGameObject *player)
{
    //TODO terminar esse factory method
    Json::Value json = FileLoader::LoadJson(JsonFile);
    Door *door = new Door(world);
    iComponentMediator *mediator = door->mediator();
    door->name = json["name"].asString();

    door->setComponents( new ScriptedInput(json["script"].asString(),mediator),
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
