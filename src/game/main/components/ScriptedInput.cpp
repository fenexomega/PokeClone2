#include "ScriptedInput.h"

#include "scripting/Lua_Wrapper.h"

ScriptedInput::ScriptedInput(std::string _script)
{
    script = new Script(_script);
}

ScriptedInput::~ScriptedInput()
{

}



void ScriptedInput::receiveMessage(int msg)
{
}


void ScriptedInput::Update(iGameObject *obj, float dt)
{

    auto objTable = Lua_Wrapper::toLua(script,obj,"obj");

    //call function
    script->getState()["Update"](objTable,dt);

    Lua_Wrapper::toObj(obj,objTable);
//    obj->acc.set(objTable["acc"]["x"],objTable["acc"]["y"]);



}
