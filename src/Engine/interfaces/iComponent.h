#ifndef ICOMPONENT
#define ICOMPONENT

#define COMP_GRAPHICS 1
#define COMP_PHYSICS 2
#define COMP_INPUT 3

/****** MESSAGES ******/
#define PLAYER_NEAR 0x10
#define PLAYER_INTERACTION 0x11

#define DISSAPEAR  0x20
#define MOVE_BACK  0x21
#define CHANGE_MAP 0x22

#define OBJS_UPDATE_POS 0x30


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

