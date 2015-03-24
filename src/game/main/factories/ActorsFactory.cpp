#include "ActorsFactory.h"

#include "main/objects/GameObject.h"
#include "main/components/PlayerPhysics.h"
#include "main/components/EnemyPhysics.h"
#include "main/objects/Map.h"
#include "main/components/ScriptedInput.h"

#include "io/FileLoader.h"
#include "main/components/AnimationController.h"

//NOTE Essa classe tem muito código duplicado

ActorsFactory::ActorsFactory()
{

}

GameObject *ActorsFactory::createPlayer(Json::Value json, Map *world)
{
    GameObject* player = new GameObject(world);
    player->name = json["name"].asString();
    player->type = json["type"].asString();

    world->Normalize(json["width"].asInt(),json["height"].asInt());
    player->pos = world->getPlayerInitialPos();

    player->setComponents(
                new ScriptedInput(json["script"].asString(),player->mediator(),player),
            new PlayerPhysics(100,Rect(0,0,json["width"].asInt(),
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

GameObject *ActorsFactory::createEnemy(Json::Value json, Map *world, Vector2D pos,
                                       GameObject* player)
{
    GameObject *gameObj = new GameObject(world);
    gameObj->name = json["name"].asString();
    gameObj->type = json["type"].asString();

    gameObj->setComponents(
                new ScriptedInput(json["script"].asString(),gameObj->mediator(),player),
            new EnemyPhysics(120,Rect(0,0,json["width"].asInt(),json["height"].asInt()/2),
            player,gameObj->mediator()),
            new AnimationController(
                new SpriteAnimation(json["sprite"].asString()
                ,json["animationFrames"].asInt()
            ,json["width"].asInt(),json["height"].asInt()),
            gameObj->mediator()));
    world->Normalize(gameObj->rect.w,gameObj->rect.h);
    gameObj->pos = pos;
    Vector2D aux = world->getOffset();

    /*Esse negócio de quebrar o rect do gameobject
      pode mais atrapalhar do que ajudar.*/
    gameObj->rect.x = aux.x;
    gameObj->rect.y = aux.y + json["height"].asInt()/2; //A hitbox tem um offset
    gameObj->rect.w = json["width"].asInt();
    gameObj->rect.h = json["height"].asInt()/2;

    return gameObj;
}

ActorsFactory::~ActorsFactory()
{

}

