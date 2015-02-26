#include "ScriptedInput.h"
#include "assets/Script.h"

#include "scripting/Lua_Wrapper.h"

ScriptedInput::ScriptedInput(std::string scriptFile, iComponentMediator *mediator)
    : cInput(mediator)
{
    _script = new Script(scriptFile);
    _script->getState().set("SendMessage",[this](int msg){ sendMessage(msg); });

}

ScriptedInput::~ScriptedInput()
{
    delete _script;
}

void ScriptedInput::receiveMessage(int msg)
{
   _script->getState()["ReceiveMessage"](msg);
}

void ScriptedInput::Update(iGameObject *obj, float dt)
{

    auto objTable = Lua_Wrapper::toLua(_script,obj,"obj");

    //call function
    _script->getState()["Update"](objTable,dt);

    Lua_Wrapper::toObj(obj,objTable);
}

Script &ScriptedInput::getScript() const
{
    return *_script;
}

