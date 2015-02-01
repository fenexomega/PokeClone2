#include "Factory.h"

#include "game/main/PlayerInput.h"
#include "game/main/AnimationController.h"
#include "game/main/PlayerPhysics.h"
#include "game/main/objects/PlayerObject.h"

#include "io/FileLoader.h"

Factory::Factory()
{

}

//Esse método carrega um json que tem as caracteristicas do player
//Junto com o mundo
iGameObject *Factory::createPlayer(std::string jsonFile, World *world)
{
    Json::Value json = FileLoader::LoadJson(jsonFile);
    iGameObject *player = new PlayerObject(new PlayerInput(),
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

Factory::~Factory()
{

}

