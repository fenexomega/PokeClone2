#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "interfaces/iGameObject.h"

class cInput;
class cPhysics;
class cGraphic;
class Map;

class GameObject : public iGameObject
{
protected:
    cInput *_input;
    cPhysics *_physics;
    cGraphic *_graphic;
    Map *_map;
public:

    GameObject(Map *map);
    void setComponents(cInput *input,cPhysics *physics,cGraphic *graphic);
    ~GameObject();

    // iGameObject interface
    void Update(float dt);
    void Render();

    Map *map() const;
    void setMap(Map *map);
};

#endif // GAMEOBJECT_H
