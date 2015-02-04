#include "Script.h"

#include "scripting/Lua_Wrapper.h"

Script::Script(std::string fileName)
    : iAsset(AS_SCRIPT)
{
    st = new lua::State();
    Lua_Wrapper::RegisterCoreFunctions(st);
    st->doFile(fileName);
}

lua::State &Script::getState() const
{
    return *st;
}


Script::~Script()
{
    delete st;
}


