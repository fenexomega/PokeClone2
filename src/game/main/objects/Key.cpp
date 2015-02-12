#include "Key.h"

#include "game/main/objects/World.h"
#include "game/main/components/ScriptedInput.h"

#include "io/FileLoader.h"

#include "game/main/components/ObjectPhysics.h"
#include "game/main/components/DecorationGraphic.h"

#include "assets/Script.h"

Key::Key(World *world)
    : GameObject(world),_active(true)
{

}

Key *Key::createKey(World *world, std::string JsonFile,iGameObject *player)
{
    Json::Value json = FileLoader::LoadJson(JsonFile);
    Key *key = new Key(world);
    iComponentMediator *mediator = key->mediator();
    key->name = json["name"].asString();

    key->setComponents(new ScriptedInput(json["script"].asString(),mediator),
            new ObjectPhysics(player,mediator),
            new DecorationGraphic(json["image"].asString(),mediator));

    ((ScriptedInput *) key->_input)->getScript().getState().set("notify",[key](void* msg){ key->Notify(msg);});

    return key;

}


Key::~Key()
{

}
