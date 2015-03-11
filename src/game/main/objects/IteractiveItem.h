#ifndef ITERACTIVEITEM_H
#define ITERACTIVEITEM_H

#include "main/objects/GameObject.h"
#include "interfaces/iSubject.h"

//TODO Essa classe poderia representar a chave


class IteractiveItem : public GameObject,public iSubject
{
private:
    bool _prop;
    bool _active;
public:
    IteractiveItem(Map *world);
    ~IteractiveItem();


};

#endif // ITERACTIVEITEM_H
