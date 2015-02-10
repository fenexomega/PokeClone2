#include "Factory.h"


#include "game/main/components/PlayerPhysics.h"
#include "game/main/components/PlayerAnimation.h"

#include "game/main/components/AnimationController.h"
#include "game/main/components/ScriptedInput.h"
#include "game/main/components/EnemyPhysics.h"

#include "game/main/components/ObjectPhysics.h"
#include "game/main/components/DecorationGraphic.h"
#include "game/main/components/DoorPhysics.h"

#include "game/main/objects/GameObject.h"

#include "io/FileLoader.h"

iGameObject* Factory::player;

//Esse método carrega um json que tem as caracteristicas do player
//Junto com o mundo
std::string Factory::getLocationDir(std::string filename)
{
    std::string aux;
    int i = filename.find_last_of('/');
    aux.append(filename.substr(0,i) + '/');
    return aux;
}

iGameObject *Factory::createPlayer(std::string jsonFile, World *world)
{

    //TODO fix do bug da posição (se o player nascer colidindo com algo,
    // ele é "empurrado" para fora
    Json::Value json = FileLoader::LoadJson(jsonFile);
    GameObject* player = new GameObject(world);
    world->Normalize(json["width"].asInt(),json["height"].asInt());
    player->pos = world->getPlayerInitialPos();
    Vector2D<int> aux = world->getOffset();

    player->setComponents(
                new ScriptedInput(json["script"].asString(),player->mediator()),
            new PlayerPhysics(2,Rect(0,0,json["width"].asInt(),
                              json["height"].asInt()/2),
            player->mediator()),
            new PlayerAnimation(aux,
                                new SpriteAnimation(json["sprite"].asString()
                                ,json["animationFrames"].asInt()
            ,json["width"].asInt(),json["height"].asInt()),
            player->mediator()));

    //TODO player deve colidir com os tiles com sua
    // coordenada especial.
    //mas a colisão com os objetos e atores deve ser feita
    //com sua posição na tela.


    //O rect do player agora é sua hitbox
    //TODO necessário?
    player->rect.x = player->pos.x;
    player->rect.y = player->pos.y;
    player->rect.w = json["width"].asInt();
    player->rect.h = json["height"].asInt()/2;



    return player;
}

iGameObject *Factory::createEnemy(std::string jsonFile, World *world, Vector2D<int> pos)
{
    Json::Value json = FileLoader::LoadJson(jsonFile);
    GameObject *enemy = new GameObject(world);
    enemy->setComponents(
                new ScriptedInput(json["script"].asString(),enemy->mediator()),
            new EnemyPhysics(2,Rect(0,0,json["width"].asInt(),json["height"].asInt()/2),
            player,enemy->mediator()),
            new AnimationController(
                new SpriteAnimation(json["sprite"].asString()
                ,json["animationFrames"].asInt()
            ,json["width"].asInt(),json["height"].asInt()),
            enemy->mediator()));
    world->Normalize(enemy->rect.w,enemy->rect.h);
    enemy->pos = pos;
    Vector2D<int> aux = world->getOffset();
    enemy->rect.x = aux.x;
    enemy->rect.y = aux.y;
    enemy->rect.w = json["width"].asInt();
    enemy->rect.h = json["height"].asInt();


    return enemy;
}

iGameObject *Factory::createInteractive(std::string jsonFile, World *world, Vector2D<int> pos)
{
    Json::Value json = FileLoader::LoadJson(jsonFile);
    GameObject *object = new GameObject(world);
    iComponentMediator *mediator = object->mediator();
    cPhysics *physics;



    object->pos = pos;
    object->rect = Rect(pos.x,pos.y,32,32);

    if(json["type"].asString().compare("door") == 0)
        physics = new DoorPhysics(player,mediator,object->rect);
    else
        physics = new ObjectPhysics(player,mediator,
                                    object->rect);

    object->setComponents(new ScriptedInput(json["script"].asString(),mediator),
            physics,
            new DecorationGraphic(json["image"].asString(),mediator));

    return object;
}

iGameObject *Factory::createWorld(std::string jsonFile)
{
    static std::string dir = "Contents/MainGame/";
    static std::string actorsDir = dir + "actors/";
    static std::string objsDir = dir + "objects/";

    World *world = new World(jsonFile);
    Json::Value json = FileLoader::LoadJson(jsonFile);

    iGameObject *obj;

    Vector2D<int>aux;


    player = createPlayer(actorsDir + json["player"]["type"].asString() + ".json",world);

    for(Uint16 i = 0; i < json["objects"].size(); ++i)
    {
        obj = createInteractive(objsDir + json["objects"][i]["type"].asString() + ".json",world,
                aux.set(json["objects"][i]["pos"][0].asInt(),
                json["objects"][i]["pos"][1].asInt()) );
        world->addGameObject(obj);
    }


    for(Uint16 i = 0; i < json["enemies"].size(); ++i)
    {
        obj = createEnemy(actorsDir + json["enemies"][i]["type"].asString() + ".json",world,
                aux.set(json["enemies"][i]["pos"][0].asInt(),
                json["enemies"][i]["pos"][1].asInt()) );
        world->addGameObject(obj);
    }




    return world;

}
