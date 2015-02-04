#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>

#include "interfaces/iGameObject.h"
#include "game/main/objects/World.h"

#define OBJ_PLAYER 0
#define OBJ_ENEMY 1


class Factory
{
public:
    Factory();
    static iGameObject *createPlayer(std::string jsonFile, World *world);
    static iGameObject *createEnemy(std::string jsonFile, World *world);

    ~Factory();
};

#endif // FACTORY_H
