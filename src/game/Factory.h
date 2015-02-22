#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>

#include "math/Vector2D.h"

class iGameObject;
class GameObject;
class World;
class WorldContext;

class Factory
{
private:
    static std::string getLocationDir(std::string filename);
public:
    static iGameObject* _player;
    static WorldContext* _worldContext;

    static iGameObject *createInteractive(std::string jsonFile, World *world, Vector2D<int> pos);

    static GameObject *createPlayer(std::string jsonFile, World *world);
    static GameObject *createEnemy(std::string jsonFile, World *world, Vector2D<int> pos);
    static GameObject *createTeleporter(std::string jsonFile, World *world, Vector2D<int> pos);

    static WorldContext *createWorldContext(std::string jsonWorldFile);
    static World *createWorld(std::string jsonFile);

};

#endif // FACTORY_H
