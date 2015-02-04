#include "Factory.h"

#include "game/main/components/PlayerInput.h"
#include "game/main/components/AnimationController.h"
#include "game/main/components/PlayerPhysics.h"
#include "game/main/components/ScriptedInput.h"
#include "game/main/components/EnemyPhysics.h"

#include "game/main/objects/PlayerObject.h"
#include "game/main/objects/EnemyObject.h"

#include "io/FileLoader.h"

Factory::Factory()
{

}

//Esse método carrega um json que tem as caracteristicas do player
//Junto com o mundo
iGameObject *Factory::createPlayer(std::string jsonFile, World *world)
{
    Json::Value json = FileLoader::LoadJson(jsonFile);
    iGameObject *player = new PlayerObject(//new PlayerInput(),
                                           new ScriptedInput("Contents/playerInput.lua"),
                                        new PlayerPhysics(2,Rect(0,0,32,16)),
                                        new AnimationController(
                                            new SpriteAnimation(json["sprite"].asString()
                                            ,json["animationFrames"].asInt()
                                        ,json["width"].asInt(),json["height"].asInt())),
                                        world);
    world->Normalize(player->rect.w,player->rect.h);
    player->pos = world->getPlayerInitialPos();
    Vector2D<int> aux = world->getOffset();
    player->rect.x = aux.x;
    player->rect.y = aux.y;
    return player;
}

iGameObject *Factory::createEnemy(std::string jsonFile, World *world)
{
    Json::Value json = FileLoader::LoadJson(jsonFile);
    iGameObject *enemy = new EnemyObject(//new PlayerInput(),
                                           new ScriptedInput("Contents/input.lua"),
                                        new EnemyPhysics(2,Rect(0,0,32,16)),
                                        new AnimationController(
                                            new SpriteAnimation(json["sprite"].asString()
                                            ,json["animationFrames"].asInt()
                                        ,json["width"].asInt(),json["height"].asInt())),
                                        world);
    world->Normalize(enemy->rect.w,enemy->rect.h);
    enemy->pos = Vector2D<int>(400,100); //world->getPlayerInitialPos();
    Vector2D<int> aux = world->getOffset();
    enemy->rect.x = aux.x;
    enemy->rect.y = aux.y;
    return enemy;
}

Factory::~Factory()
{

}

