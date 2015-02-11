#ifndef DOOR_H
#define DOOR_H

#include "interfaces/iGameObject.h"
#include "interfaces/iObserver.h"

class GameObject;
class World;

class Door : public iGameObject, public iObserver
{
private:
    GameObject *_gameObject;
    Door(World *world, bool open);
    bool _open;
    World *_world;
public:
    ~Door();

    iGameObject *createDoor(World *world,std::string JsonFile,bool open = false);

    // iGameObject interface
    void Update(float dt);
    void Render();

    // iObserver interface
    void Receive(void *MSG);
};

#endif // DOOR_H
