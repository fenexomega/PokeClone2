#ifndef ICOMPONENTMEDIATOR
#define ICOMPONENTMEDIATOR

#include "interfaces/iComponent.h"

class iComponentMediator
{
public:
    virtual void sendMessage(int msg) = 0;
    virtual void addComponent(iComponent *cmp) = 0;
    virtual ~iComponentMediator() {}

};

#endif // ICOMPONENTMEDIATOR

