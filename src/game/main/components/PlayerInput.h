#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include "interfaces/iGameObject.h"
#include "game/components/cInput.h"

class PlayerInput : public cInput
{
public:
    PlayerInput();
    void Update(iGameObject *obj,float dt);
    ~PlayerInput();



    // Component interface
private:
    void receiveMessage(int msg);
};

#endif // PLAYERINPUT_H
