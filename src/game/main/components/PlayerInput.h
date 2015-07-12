#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include "interfaces/iGameObject.h"
#include "components/cInput.h"

class PlayerInput : public cInput
{
public:
    PlayerInput(iComponentMediator *mediator);
    void Update(iGameObject *obj);
    ~PlayerInput();



    // Component interface
private:
    void receiveMessage(int msg);
};

#endif // PLAYERINPUT_H
