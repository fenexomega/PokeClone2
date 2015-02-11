#include "Door.h"

#include "io/FileLoader.h"
#include "game/main/objects/GameObject.h"

#include "game/main/components/DoorPhysics.h"
#include "game/main/components/ScriptedInput.h"

Door::Door(World *world, bool open)
    : _open(open),_world(world)
{
    _gameObject = new GameObject(world);
}

Door::~Door()
{
    delete _gameObject;
}

iGameObject *Door::createDoor(World *world, std::string JsonFile, bool open)
{
    //TODO terminar esse factory method
    Json::Value json = FileLoader::LoadJson(JsonFile);
    Door *door = new Door(world,open);
    iComponentMediator *mediator = door->_gameObject->mediator();


    cPhysics *physics = new DoorPhysics(player,mediator,gameObject->rect);
    cInput   *input   = new ScriptedInput(json["script"].asString(),mediator);


    door->_gameObject->setComponents(physics,);

}



void Door::Update(float dt)
{
    //TODO Checar se o player pegou a chave correta
}

void Door::Render()
{
    _gameObject->Render();
}


void Door::Receive(void *MSG)
{
    _open = true;
}
