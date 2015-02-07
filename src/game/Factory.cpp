#include "Factory.h"

#include "game/main/components/AnimationController.h"
#include "game/main/components/PlayerPhysics.h"
#include "game/main/components/ScriptedInput.h"
#include "game/main/components/EnemyPhysics.h"

#include "game/main/objects/GameObject.h"

#include "io/FileLoader.h"

Factory::Factory()
{

}

//Esse método carrega um json que tem as caracteristicas do player
//Junto com o mundo
iGameObject *Factory::createPlayer(std::string jsonFile, World *world)
{
    Json::Value json = FileLoader::LoadJson(jsonFile);
    GameObject *player = new GameObject(world);
    player->setComponents(
                new ScriptedInput("Contents/playerInput.lua",player->mediator()),
                new PlayerPhysics(2,Rect(0,0,json["width"].asInt(),
                                  json["height"].asInt()/2),
            player->mediator()),
            new AnimationController(
                new SpriteAnimation(json["sprite"].asString()
                ,json["animationFrames"].asInt()
            ,json["width"].asInt(),json["height"].asInt()),
            player->mediator()));
    world->Normalize(player->rect.w,player->rect.h);
    player->pos = world->getPlayerInitialPos();
    Vector2D<int> aux = world->getOffset();
    player->rect.x = aux.x;
    player->rect.y = aux.y;
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
    enemy->pos = pos; //world->getPlayerInitialPos();
    Vector2D<int> aux = world->getOffset();
    enemy->rect.x = aux.x;
    enemy->rect.y = aux.y;
    return enemy;
}

iGameObject *Factory::createInteractive(std::string jsonFile, World *world, Vector2D<int> pos)
{
    Json::Value json = FileLoader::LoadJson(jsonFile);
    GameObject *object = new GameObject(world);
    object->setComponents(
                new ScriptedInput("Contents/input.lua",object->mediator()),
                new EnemyPhysics(2,Rect(0,0,json["width"].asInt(),json["height"].asInt()/2),object->mediator()),
            new AnimationController(
                new SpriteAnimation(json["sprite"].asString()
                ,json["animationFrames"].asInt()
            ,json["width"].asInt(),json["height"].asInt()),
            object->mediator()));
    world->Normalize(object->rect.w,object->rect.h);
    object->pos = pos; //world->getPlayerInitialPos();
    Vector2D<int> aux = world->getOffset();
    object->rect.x = aux.x;
    object->rect.y = aux.y;
    return object;
}

Factory::~Factory()
{

}

