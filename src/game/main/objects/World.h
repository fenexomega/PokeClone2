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
    Map *_actualMap{};
    std::vector<Map *> _maps;
    GameObject *_player;
    bool _mapHasChanged = false;
    Map *_outerMap{};


    Map* findMapByName(std::string mapName);
public:
    World();
    ~World();
    Map *actualMap() const;
    void setActualMap(Map *map);
    void setActualMap(std::string mapName);
    void setActualMap(std::string mapName, Vector2D playerPos);

    void addMap(Map *map);

    void Move(Vector2D v);

    //Function to alerts that the world changed,
    //needs to call update again, on the other frame

    Map * at(int i);

    // iGameObject interface
    void Update(float dt);
    void Render();
    GameObject *player() const;
    void setPlayer(GameObject *player);
};

#endif // WORLDCONTEXT_H
