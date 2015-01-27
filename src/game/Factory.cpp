#include "Factory.h"

#include "game/main/PlayerInput.h"
#include "game/main/AnimationController.h"

#include "io/FileLoader.h"

Factory::Factory()
{

}

GameObject *Factory::createPlayer(std::string jsonFile, World *world)
{
    Json::Value json = *(FileLoader::LoadJson(jsonFile));
    GameObject *player = new GameObject(new PlayerInput(),
                                        nullptr,
                                        new AnimationController(
                                            new SpriteAnimation(json["sprite"].asString()
                                            ,json["animationFrames"].asInt()
                                        ,json["width"].asInt(),json["height"].asInt())),
                                        world);
    return player;
}

Factory::~Factory()
{

}

