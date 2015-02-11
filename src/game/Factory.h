#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>


#define OBJ_PLAYER 0
#define OBJ_ENEMY 1

class iGameObject;
class World;

#include "math/Vector2D.h"
//TODO a fabrica vai criar o mundo e
// por os inimigos nele
class Factory
{
private:
    static std::string getLocationDir(std::string filename);
public:
    static iGameObject* player;
    static iGameObject *createPlayer(std::string jsonFile, World *world);
    static iGameObject *createEnemy(std::string jsonFile, World *world, Vector2D<int> pos);
    static iGameObject *createInteractive(std::string jsonFile, World *world, Vector2D<int> pos);
    static iGameObject *createWorld(std::string jsonFile);
};

#endif // FACTORY_H
