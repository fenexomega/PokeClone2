#ifndef SCRIPTEDINPUT_H
#define SCRIPTEDINPUT_H

#include "game/components/cInput.h"

class Script;

class ScriptedInput : public cInput
{
private:
    Script *_script;
public:
    ScriptedInput(std::string scriptFile, iComponentMediator *mediator);
    ~ScriptedInput();

    // iComponent interface
    void receiveMessage(int msg);

    // cInput interface
    void Update(iGameObject *obj,float dt);

    Script &getScript() const;

};

#endif // SCRIPTEDINPUT_H
