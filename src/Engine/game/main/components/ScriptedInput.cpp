#include "ScriptedInput.h"
#include "assets/Script.h"

#include "scripting/Lua_Wrapper.h"

#include "interfaces/iGameObject.h"



ScriptedInput::ScriptedInput(std::string scriptFile, iComponentMediator *mediator,iGameObject *player)
    : cInput(mediator),_player(player)
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

    //Passa a posição do player para o lua
    _script->getState().set("player",Lua_Wrapper::toLua(_script,_player,"player"));

    //call function
    _script->getState()["Update"](objTable,dt);

    Lua_Wrapper::toObj(obj,objTable);
}

Script &ScriptedInput::getScript() const
{
    return *_script;
}

