#include "IteractiveFactory.h"

#include "io/FileLoader.h"
#include "main/objects/IteractiveItem.h"
#include "main/objects/GameObject.h"
#include "main/components/ScriptedInput.h"
#include "main/components/ObjectPhysics.h"
#include "main/components/TeleporterPhysics.h"
#include "main/components/DecorationGraphic.h"
#include "main/objects/World.h"

#include "assets/Script.h"
IteractiveFactory::IteractiveFactory()
{

}

GameObject *IteractiveFactory::createKey(
        Map *world, Json::Value json,iGameObject *player)
{
    IteractiveItem *key = new IteractiveItem(world);
    iComponentMediator *mediator = key->mediator();
    key->name = json["name"].asString();
    key->type = json["type"].asString();

    auto iScript = new ScriptedInput(
                json["script"].asString(),
            mediator,player);

    key->setComponents(iScript,
                       new ObjectPhysics(player,mediator),
                       new DecorationGraphic(
                           json["image"].asString(),
                       mediator));

    ScriptedInput *si = iScript;

    si->getScript().getState().set("notify",[key]
                                   (void* msg){ key->Notify(msg);});

    return dynamic_cast<GameObject*>(key);
}

GameObject *IteractiveFactory::createTeleporter(
        Map *world, Json::Value json,
        iGameObject *player, World *worldContext)
{
    GameObject *teleporter = new GameObject(world);
    iComponentMediator *mediator = teleporter->mediator();

    teleporter->name = json["name"].asString();
    teleporter->setComponents(new ScriptedInput(
                                  json["script"].asString(),
                              mediator,player),
            new TeleporterPhysics(mediator,
                                  player,worldContext),
            new DecorationGraphic(json["image"].asString(),
            mediator));

    return teleporter;
}

void IteractiveFactory::changeMap(iGameObject *obj,Json::Value json)
{
    GameObject* gameobj = dynamic_cast<GameObject*>(obj);
    auto physics = dynamic_cast<TeleporterPhysics*>(gameobj->physics());
    physics->setMapToTeleport( json["map"].asString(),
            Vector2D(json["posTele"][0].asInt(),
            json["posTele"][1].asInt()));
}


IteractiveFactory::~IteractiveFactory()
{

}

