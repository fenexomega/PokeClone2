#include "ScriptedInput.h"
#include "assets/Script.h"

#include "scripting/Lua_Wrapper.h"

ScriptedInput::ScriptedInput(std::string _script,iComponentMediator *mediator)
    : cInput(mediator)
{
    script = new Script(_script);
    script->getState().set("SendMessage",[this](int msg){ sendMessage(msg); });

}

ScriptedInput::~ScriptedInput()
{

}



void ScriptedInput::receiveMessage(int msg)
{
   script->getState()["ReceiveMessage"](msg);

}


void ScriptedInput::Update(iGameObject *obj, float dt)
{

    auto objTable = Lua_Wrapper::toLua(script,obj,"obj");

    //call function
    script->getState()["Update"](objTable,dt);

    Lua_Wrapper::toObj(obj,objTable);



}

Script &ScriptedInput::getScript() const
{
    return *script;
}

