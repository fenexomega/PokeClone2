#include "Lua_Wrapper.h"

#include "systems/sysScripting.h"
#include "systems/sysInput.h"

#include "util/Logger.h"

std::vector<Script *> Lua_Wrapper::scripts;

void Lua_Wrapper::RegisterCoreFunctions(lua::State* state)
{
    state->doFile("Contents/keys.lua");
    state->set("isKeyPressed",&sysInput::isKeyPressed);
    state->set("isKeyDown",&sysInput::isKeyDown);
    state->set("isKeyUp",&sysInput::isKeyUp);


}

Lua_Wrapper::Lua_Wrapper()
{

}

lua::Value Lua_Wrapper::toLua(Script *script,iGameObject *obj,std::string varName)
{
    script->getState().set(varName.c_str(),lua::Table());
    auto objTable = script->getState()[varName.c_str()];

    // set acc vector to Lua table
    objTable.set("acc",lua::Table());
    objTable["acc"].set("x",obj->acc.x);
    objTable["acc"].set("y",obj->acc.y);

    // pos
    objTable.set("pos",lua::Table());
    objTable["pos"].set("x",obj->pos.x);
    objTable["pos"].set("y",obj->pos.y);

    // rect
    objTable.set("rect",lua::Table());
    objTable["rect"].set("x",obj->rect.x);
    objTable["rect"].set("y",obj->rect.y);
    objTable["rect"].set("w",obj->rect.w);
    objTable["rect"].set("h",obj->rect.h);

    return objTable;
}

void Lua_Wrapper::toObj(iGameObject *obj, lua::Value objTable)
{
    obj->acc.set(objTable["acc"]["x"],objTable["acc"]["y"]);
    obj->pos.set(objTable["pos"]["x"],objTable["pos"]["y"]);
    obj->rect.x = objTable["rect"]["x"];
    obj->rect.y = objTable["rect"]["y"];
    obj->rect.w = objTable["rect"]["w"];
    obj->rect.h = objTable["rect"]["h"];


}

void Lua_Wrapper::ReloadScripts()
{
    for(auto i : scripts)
        i->Reload();
    PRINT("Scripts recarregados");
}

void Lua_Wrapper::SubscribleScript(Script *script)
{
    scripts.push_back(script);
}

void Lua_Wrapper::Unsubscrible(Script *script)
{
    for(auto i = scripts.begin(); i != scripts.end();++i)
    {
        if(*i == script)
        {
            scripts.erase(i);
            return;
        }
    }
    return;
}

Lua_Wrapper::~Lua_Wrapper()
{

}

