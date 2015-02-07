#ifndef ICOMPONENT
#define ICOMPONENT

#define COMP_GRAPHICS 1
#define COMP_PHYSICS 2
#define COMP_INPUT 3

#include "interfaces/iComponentMediator.h"

class iComponent
{
private:
    iComponentMediator *_mediator;
public:
    iComponent(iComponentMediator *mediator)
       : _mediator(mediator)
    {
        mediator->addComponent(this);
    }

     void sendMessage(int msg)
    {
        _mediator->sendMessage(msg);
    }

    virtual void receiveMessage(int msg) = 0;

    virtual ~iComponent()
    {
    }
};

#endif // ICOMPONENT

