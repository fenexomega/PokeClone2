#ifndef ITERACTIVEITEM_H
#define ITERACTIVEITEM_H

#include "interfaces/iGameObject.h"
//TODO relação chave-porta


class IteractiveItem : public iGameObject
{
private:
    bool _prop;
    bool _active;
public:
    IteractiveItem();
    ~IteractiveItem();

    // iGameObject interface
    void Update(float dt);
    void Render();
};

#endif // ITERACTIVEITEM_H
