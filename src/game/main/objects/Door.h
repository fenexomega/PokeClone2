#ifndef DOOR_H
#define DOOR_H

//#include "interfaces/iGameObject.h"
#include "interfaces/iObserver.h"
#include "game/main/objects/GameObject.h"


class Door : public GameObject, public iObserver
{
private:
    Door(World *world);
    std::string _keyName;
public:
    bool _open;
    ~Door();

    static Door *createDoor(World *world, std::string JsonFile, iGameObject *player);

    // iObserver interface
    void Receive(void *MSG);
    std::string keyName() const;
    void setKeyName(const std::string &keyName);
};

#endif // DOOR_H