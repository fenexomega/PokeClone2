#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "math/Vector2D.h"


class Map;



//Implemetando State Pattern

class World
{
private:
    Map *_actualMap;
    std::vector<Map *> _maps;

public:
    World();
    ~World();
    Map *actualMap() const;
    void setActualMap(Map *actualMap);
    void setActualMap(std::string mapName);
    void addMap(Map *map);


    Map * at(int i);

    // iGameObject interface
    void Update(float dt);
    void Render();
};

#endif // WORLDCONTEXT_H
