#include "Lua_Wrapper.h"

#include "systems/sysScripting.h"
#include "systems/sysInput.h"

void Lua_Wrapper::RegisterCoreFunctions()
{
    lua::State* state = sysScripting::getState();
    state->set("isKeyPressed",&sysInput::isKeyPressed);
    state->set("isKeyDown",&sysInput::isKeyDown);
    state->set("isKeyUp",&sysInput::isKeyUp);


}

Lua_Wrapper::Lua_Wrapper()
{

}

lua::Value Lua_Wrapper::toLua(iGameObject *obj,std::string varName)
{
    sysScripting::getState()->set(varName.c_str(),lua::Table());
    auto objTable = (*sysScripting::getState())[varName.c_str()];

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

Lua_Wrapper::~Lua_Wrapper()
{

}

