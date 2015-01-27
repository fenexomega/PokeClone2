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
    world->setPlayerDimensions(player->rect.w,player->rect.h);
    return player;
}

Factory::~Factory()
{

}

