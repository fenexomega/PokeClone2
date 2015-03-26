#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>

#include "math/Vector2D.h"

class iGameObject;
class GameObject;
class Map;
class World;

namespace Json
{
    class Value;
}

class Factory
{
private:
    static std::string getLocationDir(std::string filename);
public:
    static GameObject* _player;
    static World* _worldContext;

    static iGameObject *createInteractive(std::string jsonFile,
                                          Map *world, Vector2D pos,
                                          Json::Value auxJson);

    //Esse método carrega um json que tem as caracteristicas do player
    //Junto com o mundo
    static GameObject *createPlayer(std::string jsonFile, Map *world);

    //Criar Inimigo
    static GameObject *createEnemy(std::string jsonFile, Map *world, Vector2D pos);

    //Criar Teleporter
    static GameObject *createTeleporter(std::string jsonFile, Map *world, Vector2D pos);

    //Criar Mundo
    static World *createWorld(std::string jsonWorldFile);

    //Criar Mapa
    static Map *createMap(std::string jsonFile);

    static void Init();

};

#endif // FACTORY_H
