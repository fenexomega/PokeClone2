#include "Factory.h"

#include "interfaces/iGameObject.h"

//GRAPHICS
#include "game/main/components/PlayerAnimation.h"
#include "game/main/components/DecorationGraphic.h"
#include "game/main/components/AnimationController.h"

//INPUT
#include "game/main/components/ScriptedInput.h"

//PHYSICS
#include "game/main/components/ObjectPhysics.h"
#include "game/main/components/DoorPhysics.h"
#include "game/main/components/EnemyPhysics.h"
#include "game/main/components/PlayerPhysics.h"
#include "game/main/components/TeleporterPhysics.h"

#include "game/main/objects/GameObject.h"
#include "game/main/objects/Map.h"
#include "game/main/objects/World.h"
#include "game/main/objects/Key.h"
#include "game/main/objects/Door.h"

#include "io/FileLoader.h"

#include "util/Logger.h"

GameObject* Factory::_player;
World* Factory::_worldContext;
//TODO Essa classe está se tornando monolitica

//TODO Essa classe tem muito código duplicado

/*  Pegar a localização do arquivo
 *  i.e. se a entrada é "/loca/liza/cao/arquivo.txt",
 *  ela retorna "/loca/liza/cao/"
 */
std::string Factory::getLocationDir(std::string filename)
{
    std::string aux;
    int i = filename.find_last_of('/');
    aux.append(filename.substr(0,i+1));
    return aux;
}



GameObject *Factory::createPlayer(std::string jsonFile, Map *world)
{

    //TODO BUG? fix do bug da posição (se o player nascer colidindo com algo,
    // ele é "empurrado" para fora e fica preso)
    Json::Value json = FileLoader::LoadJson(jsonFile);
    GameObject* player = new GameObject(world);
    player->name = json["name"].asString();
    player->type = json["type"].asString();

    world->Normalize(json["width"].asInt(),json["height"].asInt());
    player->pos = world->getPlayerInitialPos();

    player->setComponents(
                new ScriptedInput(json["script"].asString(),player->mediator()),
            new PlayerPhysics(2,Rect(0,0,json["width"].asInt(),
                              json["height"].asInt()/2),
            player->mediator()),
            new AnimationController(
                new SpriteAnimation(json["sprite"].asString()
                ,json["animationFrames"].asInt()
            ,json["width"].asInt(),json["height"].asInt()),
            player->mediator()));

    //player deve colidir com os tiles com sua
    // coordenada especial.
    //mas a colisão com os objetos e atores deve ser feita
    //com sua posição na tela.


    //O rect do player agora é sua hitbox
    player->rect.x = world->offset.x;
    player->rect.y = world->offset.y + json["height"].asInt()/2; //A hitbox tem um offset
    player->rect.w = json["width"].asInt();
    player->rect.h = json["height"].asInt()/2;



    return player;
}

GameObject *Factory::createEnemy(std::string jsonFile, Map *world, Vector2D<int> pos)
{
    Json::Value json = FileLoader::LoadJson(jsonFile);
    GameObject *gameObj = new GameObject(world);
    gameObj->name = json["name"].asString();
    gameObj->type = json["type"].asString();

    gameObj->setComponents(
                new ScriptedInput(json["script"].asString(),gameObj->mediator()),
            new EnemyPhysics(2,Rect(0,0,json["width"].asInt(),json["height"].asInt()/2),
            _player,gameObj->mediator()),
            new AnimationController(
                new SpriteAnimation(json["sprite"].asString()
                ,json["animationFrames"].asInt()
            ,json["width"].asInt(),json["height"].asInt()),
            gameObj->mediator()));
    world->Normalize(gameObj->rect.w,gameObj->rect.h);
    gameObj->pos = pos;
    Vector2D<int> aux = world->getOffset();

    /*Esse negócio de quebrar o rect do gameobject
      pode mais atrapalhar do que ajudar.*/
    gameObj->rect.x = aux.x;
    gameObj->rect.y = aux.y + json["height"].asInt()/2; //A hitbox tem um offset
    gameObj->rect.w = json["width"].asInt();
    gameObj->rect.h = json["height"].asInt()/2;


    return gameObj;
}

GameObject *Factory::createTeleporter(std::string jsonFile, Map *world, Vector2D<int> pos)
{
    GameObject *teleporter = new GameObject(world);
    Json::Value json = FileLoader::LoadJson(jsonFile);
    iComponentMediator *mediator = teleporter->mediator();

    teleporter->name = json["name"].asString();
    teleporter->setComponents(new ScriptedInput(json["script"].asString(),mediator),
            new TeleporterPhysics(mediator,_player,_worldContext,
                                  json["map"].asString(),
            Vector2D<int>(json["pos"][0].asInt(),
            json["pos"][1].asInt())),
            new DecorationGraphic(json["image"].asString(),mediator));

    return teleporter;
}

iGameObject *Factory::createInteractive(std::string jsonFile, Map *world, Vector2D<int> pos)
{
    Json::Value json = FileLoader::LoadJson(jsonFile);
    iGameObject *obj = NULL;


    if(json["type"].asString() == "door")
    {
        //TODO inconsistencia?
        /*** cria com factory method enquanto o resto a *
         * fábrica mesmo que constroi                 ***/
        obj = Door::createDoor(world,jsonFile,_player);

        //Registrar porta na chave
        Door *door = dynamic_cast<Door*>(obj);
        for(iGameObject *key : world->gameObjects)
        {
            if(key->name == door->keyName() )
            {
                ((Key *) key)->AddObserver(((Door*)obj ));
            }
        }

    }
    else if (json["type"].asString() == "key")
    {
        //inconsistencia?
        obj = Key::createKey(world,jsonFile,_player);
    }
    else if (json["type"].asString() == "teleporter")
        //inconsistencia?
        obj = createTeleporter(jsonFile,world,pos);

    obj->pos = pos;
    obj->rect = Rect(pos.x,pos.y,json["width"].asInt(),
            json["height"].asInt());

    return obj;
}

World *Factory::createWorld(std::string jsonWorldFile)
{
    _worldContext = new World;
    Json::Value json = FileLoader::LoadJson(jsonWorldFile);

    for(auto i = 0; i < json["maps"].size() ; ++i )
    {
        LOG("Criando " + json["maps"][i].asString());
        _worldContext->addMap( createMap( json["maps"][i].asString() ) );
    }

    _worldContext->setPlayer(_player);
    _worldContext->setActualMap(_worldContext->at(0));


    return _worldContext;
}

Map *Factory::createMap(std::string jsonFile)
{
    static std::string dir = "Contents/MainGame/";
    static std::string actorsDir = dir + "actors/";
    static std::string objsDir = dir + "objects/";

    Map *worldMap = new Map(jsonFile);
    Json::Value json = FileLoader::LoadJson(jsonFile);
    iGameObject *obj;
    Vector2D<int>aux;

    worldMap->name = json["name"].asString();

    /*TODO o player não deveria ser criado dentro do mapa
    * e sim no mundo.
    * Talvez nem nele.
    */
    if(_player == nullptr)
        _player = createPlayer(actorsDir + json["player"]["type"].asString() + ".json",worldMap);

    worldMap->player = _player;

    for(Uint16 i = 0; i < json["objects"].size(); ++i)
    {
        LOG("Criando " + json["objects"][i]["type"].asString());
        obj = createInteractive(objsDir + json["objects"][i]["type"].asString() + ".json",worldMap,
                aux.set(json["objects"][i]["pos"][0].asInt(),
                json["objects"][i]["pos"][1].asInt()) );
        worldMap->addGameObject(obj);
    }


    for(Uint16 i = 0; i < json["enemies"].size(); ++i)
    {
        LOG("Criando " + json["objects"][i]["type"].asString());
        obj = createEnemy(actorsDir + json["enemies"][i]["type"].asString() + ".json",worldMap,
                aux.set(json["enemies"][i]["pos"][0].asInt(),
                json["enemies"][i]["pos"][1].asInt()) );
        worldMap->addGameEnemies(obj);
    }

    return worldMap;

}

void Factory::Init()
{
    _player = nullptr;
}
