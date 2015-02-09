#ifndef SCRIPTEDINPUT_H
#define SCRIPTEDINPUT_H

#include "game/components/cInput.h"

class Script;

class ScriptedInput : public cInput
{
private:
    Script *script;
public:
    ScriptedInput(std::string _script,iComponentMediator *mediator);
    ~ScriptedInput();

    // iComponent interface
    void receiveMessage(int msg);

    // cInput interface
    void Update(iGameObject *obj,float dt);

};

#endif // SCRIPTEDINPUT_H
