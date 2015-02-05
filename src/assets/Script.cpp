#include "Script.h"

#include "scripting/Lua_Wrapper.h"

Script::Script(std::string fileName)
    : iAsset(AS_SCRIPT),file(fileName)
{
    st = new lua::State();
    Lua_Wrapper::RegisterCoreFunctions(st);
    st->doFile(fileName);
    Lua_Wrapper::SubscribleScript(this);
}

lua::State &Script::getState() const
{
    return *st;
}

void Script::Reload()
{
    st->doFile(file);
}


Script::~Script()
{
    Lua_Wrapper::Unsubscrible(this);
    delete st;
}


