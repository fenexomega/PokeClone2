#ifndef WORLD_H
#define WORLD_H

#include "math/Vector2D.h"

class Map;



//Implemetando State Pattern

class World
{
private:
    Map *_world;
public:

    World();
    ~World();
    Map *world() const;
    void setWorld(Map *world);

    // iGameObject interface
    void Update(float dt);
    void Render();
};

#endif // WORLDCONTEXT_H
