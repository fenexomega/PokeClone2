#include "Factory.h"

#include "main/objects/Map.h"
#include "main/objects/World.h"
#include "main/objects/Door.h"
#include "main/objects/IteractiveItem.h"

#include "io/FileLoader.h"

#include "util/Logger.h"

#include "main/factories/IteractiveFactory.h"
#include "main/factories/ActorsFactory.h"

GameObject* Factory::_player;
World* Factory::_worldContext;


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
    // BUG posição (se o player nascer colidindo com algo,
    // ele é "empurrado" para fora e fica preso)
    Json::Value json = FileLoader::LoadJson(jsonFile);

    return ActorsFactory::createPlayer(json,world);
}

GameObject *Factory::createEnemy(std::string jsonFile, Map *world, Vector2D pos)
{
    Json::Value json = FileLoader::LoadJson(jsonFile);

    return ActorsFactory::createEnemy(json,world,pos,_player);
}

iGameObject *Factory::createInteractive(std::string jsonFile, Map *world, Vector2D pos)
{
    Json::Value json = FileLoader::LoadJson(jsonFile);
    iGameObject *obj = NULL;


    if(json["type"].asString() == "door")
    {
        //NOTE inconsistencia?
        /*** cria com factory method enquanto o resto a *
         * fábrica mesmo que constroi                 ***/
        obj = Door::createDoor(world,jsonFile,_player);

        //Registrar porta na chave
        Door *door = dynamic_cast<Door*>(obj);
        for(iGameObject *key : world->gameObjects)
        {
            if(key->name == door->keyName() )
            {
                ((IteractiveItem *) key)->AddObserver(((Door*)obj ));
            }
        }

    }
    else if (json["type"].asString() == "key")
    {
        //inconsistencia?
        obj = IteractiveFactory::createKey(world,json,_player);
    }
    else if (json["type"].asString() == "teleporter")
        //inconsistencia?
        obj = IteractiveFactory::createTeleporter(world,json,_player,_worldContext);
    obj->pos = pos;
    obj->rect = Rect(pos.x,pos.y,json["width"].asInt(),
            json["height"].asInt());

    return obj;
}

World *Factory::createWorld(std::string jsonWorldFile)
{
    _worldContext = new World;
    Json::Value json = FileLoader::LoadJson(jsonWorldFile);

    for(unsigned int i = 0; i < json["maps"].size() ; ++i )
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
    Vector2D aux;

    worldMap->name = json["name"].asString();

    /*NOTE: o player não deveria ser criado dentro do mapa
    * e sim no mundo.
    * Talvez nem nele.
    */
    if(_player == nullptr)
        _player = createPlayer(actorsDir + json["player"]["type"].asString() + ".json",worldMap);

    worldMap->player = _player;

    LOG("Objs.Size = " + TOSTR(json["objects"].size()) );
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
    if(_player)
        delete _player;
    _player = nullptr;
}
