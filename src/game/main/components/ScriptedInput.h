#ifndef SCRIPTEDINPUT_H
#define SCRIPTEDINPUT_H

#include "components/cInput.h"


class iGameObject;
class Script;

class ScriptedInput : public cInput
{
private:
    Script *_script;
    iGameObject *_player;
public:
    ScriptedInput(std::string scriptFile, iComponentMediator *mediator,iGameObject *player);
    ~ScriptedInput();

    // iComponent interface
    void receiveMessage(int msg);

    // cInput interface
    void Update(iGameObject *obj,float dt);

    Script &getScript() const;

};

#endif // SCRIPTEDINPUT_H
