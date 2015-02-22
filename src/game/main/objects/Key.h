#ifndef KEY_H
#define KEY_H

#include "interfaces/iSubject.h"
#include "game/main/objects/GameObject.h"

//TODO relacao porta-chave
//usando observer


class Key : public GameObject,public iSubject
{
private:
    Key(World *world);
    bool _active;
public:
    //factory method
    static Key *createKey(World *world, std::string JsonFile, iGameObject *player);
    ~Key();


};

#endif // KEY_H