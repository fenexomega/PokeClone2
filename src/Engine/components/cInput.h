#ifndef CINPUT
#define CINPUT

#include "interfaces/iGameObject.h"
#include "interfaces/iComponent.h"


class cInput : public iComponent
{
public:
    cInput(iComponentMediator *mediator)
        : iComponent(mediator){}

    virtual void Update(iGameObject *player,float dt) {}
    virtual ~cInput() {}
};

#endif // CINPUT

