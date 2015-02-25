#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>

#include "math/Vector2D.h"

class iGameObject;
class GameObject;
class Map;
class World;

class Factory
{
private:
    static std::string getLocationDir(std::string filename);
public:
    static GameObject* _player;
    static World* _worldContext;

    static iGameObject *createInteractive(std::string jsonFile, Map *world, Vector2D<int> pos);

    static GameObject *createPlayer(std::string jsonFile, Map *world);
    static GameObject *createEnemy(std::string jsonFile, Map *world, Vector2D<int> pos);
    static GameObject *createTeleporter(std::string jsonFile, Map *world, Vector2D<int> pos);

    static World *createWorld(std::string jsonWorldFile);
    static Map *createMap(std::string jsonFile);

};

#endif // FACTORY_H
