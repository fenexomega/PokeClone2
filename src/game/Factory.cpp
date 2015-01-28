#include "Factory.h"

#include "game/main/PlayerInput.h"
#include "game/main/AnimationController.h"
#include "game/main/PlayerPhysics.h"

#include "io/FileLoader.h"

Factory::Factory()
{

}

//Esse método carrega um json que tem as caracteristicas do player
GameObject *Factory::createPlayer(std::string jsonFile, World *world)
{
    Json::Value json = FileLoader::LoadJson(jsonFile);
    GameObject *player = new GameObject(new PlayerInput(),
                                        new PlayerPhysics(2),
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

Factory::~Factory()
{

}

