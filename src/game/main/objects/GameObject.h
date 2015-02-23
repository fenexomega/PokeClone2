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
public:
    Map *_map;

    GameObject(Map *world);
    void setComponents(cInput *input,cPhysics *physics,cGraphic *graphic);
    ~GameObject();

    // iGameObject interface
    void Update(float dt);
    void Render();
};

#endif // GAMEOBJECT_H
