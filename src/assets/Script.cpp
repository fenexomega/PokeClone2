#include "Script.h"

#include "scripting/Lua_Wrapper.h"

#include "util/Logger.h"

Script::Script(std::string fileName)
    : iAsset(AS_SCRIPT),file(fileName)
{
    st = new lua::State();
    Lua_Wrapper::RegisterCoreFunctions(st);
    try{
        st->doFile(file);
    }
    catch(std::runtime_error)
    {
        st->doFile(file + "c");
    }

    LOG("Loaded\tLua\t" + file);
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


