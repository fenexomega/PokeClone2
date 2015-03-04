#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "math/Vector2D.h"


class Map;
class GameObject;


//Implemetando State Pattern

class World
{
private:
    Map *_actualMap;
    std::vector<Map *> _maps;
    GameObject *_player;

    Map* findMapByName(std::string mapName);
public:
    World();
    ~World();
    Map *actualMap() const;
    void setActualMap(Map *map);
    void setActualMap(std::string mapName);
    void setActualMap(std::string mapName, Vector2D<int> playerPos);

    void addMap(Map *map);


    Map * at(int i);

    // iGameObject interface
    void Update(float dt);
    void Render();
    GameObject *player() const;
    void setPlayer(GameObject *player);
};

#endif // WORLDCONTEXT_H