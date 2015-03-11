#ifndef DOOR_H
#define DOOR_H

//#include "interfaces/iGameObject.h"
#include "interfaces/iObserver.h"
#include "main/objects/GameObject.h"


class Door : public GameObject, public iObserver
{
private:
    Door(Map *world);
    std::string _keyName;
public:
    bool _open;
    ~Door();

    static Door *createDoor(Map *world, std::string JsonFile, iGameObject *player);

    // iObserver interface
    void Receive(void *MSG);
    std::string keyName() const;
    void setKeyName(const std::string &keyName);
};

#endif // DOOR_H
