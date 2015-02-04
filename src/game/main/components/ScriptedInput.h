#ifndef SCRIPTEDINPUT_H
#define SCRIPTEDINPUT_H

#include "game/components/cInput.h"
#include "assets/Script.h"

class ScriptedInput : public cInput
{
private:
    Script *script;
public:
    ScriptedInput(std::string _script);
    ~ScriptedInput();

    // iComponent interface
    void receiveMessage(int msg);

    // cInput interface
    void Update(iGameObject *obj);
};

#endif // SCRIPTEDINPUT_H
