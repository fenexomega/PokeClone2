#ifndef OBJECTINPUT_H
#define OBJECTINPUT_H

#include "game/components/cInput.h"
#include "components/MessageSender.h"

#define PLAYER_COLLIDING 1

class ObjectInput : public cInput
{
private:
    bool isAble;
public:
    ObjectInput(iComponentMediator *mediator);
    ~ObjectInput();

    // iComponent interface
    void receiveMessage(int msg);

    // cInput interface
    void Update(iGameObject *player, float dt);
};

#endif // OBJECTINPUT_H
