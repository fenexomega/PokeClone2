#ifndef CINPUT
#define CINPUT

#include "interfaces/iGameObject.h"
#include "interfaces/iComponent.h"


class cInput : public iComponent
{
public:
    virtual void Update(iGameObject *player,float dt) {}
};

#endif // CINPUT

