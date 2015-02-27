#ifndef ICOMPONENT
#define ICOMPONENT

#define COMP_GRAPHICS 1
#define COMP_PHYSICS 2
#define COMP_INPUT 3

/****** MESSAGES ******/
#define PLAYER_NEAR 1
#define PLAYER_INTERACTION 2

#define DISSAPEAR  3
#define MOVE_BACK  4
#define CHANGE_MAP 5



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

