#include "Factory.h"


#include "game/main/components/PlayerPhysics.h"
#include "game/main/components/PlayerAnimation.h"

#include "game/main/components/AnimationController.h"
#include "game/main/components/ScriptedInput.h"
#include "game/main/components/EnemyPhysics.h"

#include "game/main/components/ObjectPhysics.h"
#include "game/main/components/DecorationGraphic.h"

#include "game/main/objects/GameObject.h"

#include "io/FileLoader.h"

GameObject* Factory::player;

Factory::Factory()
{

}

//Esse método carrega um json que tem as caracteristicas do player
//Junto com o mundo
iGameObject *Factory::createPlayer(std::string jsonFile, World *world)
{

    //TODO fix do bug da posição (se o player nascer colidindo com algo,
    // ele é "empurrado" para fora
    Json::Value json = FileLoader::LoadJson(jsonFile);
    player = new GameObject(world);
    world->Normalize(json["width"].asInt(),json["height"].asInt());
    player->pos = world->getPlayerInitialPos();
    Vector2D<int> aux = world->getOffset();

    player->setComponents(
                new ScriptedInput("Contents/playerInput.lua",player->mediator()),
                new PlayerPhysics(2,Rect(0,0,json["width"].asInt(),
                                  json["height"].asInt()/2),
            player->mediator()),
            new PlayerAnimation(aux,
                                new SpriteAnimation(json["sprite"].asString()
                                ,json["animationFrames"].asInt()
            ,json["width"].asInt(),json["height"].asInt()),
            player->mediator()));

    //O rect do player agora é sua hitbox
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
                new ScriptedInput("Contents/input.lua",enemy->mediator()),
                new EnemyPhysics(2,Rect(0,0,json["width"].asInt(),json["height"].asInt()/2),enemy->mediator()),
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
    return enemy;
}

iGameObject *Factory::createInteractive(std::string jsonFile, World *world, Vector2D<int> pos)
{
    Json::Value json = FileLoader::LoadJson(jsonFile);
    GameObject *object = new GameObject(world);
    iComponentMediator *mediator = object->mediator();
    object->pos = pos;
    object->rect = Rect(pos.x,pos.y,32,32);
    object->setComponents(new ScriptedInput("Contents/objectInput.lua",mediator),
                          new ObjectPhysics(player,mediator,
                                            object->rect),
                          new DecorationGraphic("Contents/key0.png",mediator));

    return object;
}

Factory::~Factory()
{

}

