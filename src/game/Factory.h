#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>

#include "interfaces/iGameObject.h"
#include "game/main/objects/World.h"

#define OBJ_PLAYER 0
#define OBJ_ENEMY 1

class GameObject;

//TODO a fabrica vai criar o mundo e
// por os inimigos nele
class Factory
{
public:
    static GameObject* player;
    Factory();
    static iGameObject *createPlayer(std::string jsonFile, World *world);
    static iGameObject *createEnemy(std::string jsonFile, World *world, Vector2D<int> pos);
    static iGameObject *createInteractive(std::string jsonFile, World *world, Vector2D<int> pos);
    ~Factory();
};

#endif // FACTORY_H
