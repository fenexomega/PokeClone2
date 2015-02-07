#include "Script.h"

#include "scripting/Lua_Wrapper.h"

#include "util/Logger.h"



Script::Script(std::string fileName)
    : iAsset(AS_SCRIPT),file(fileName)
{
#ifdef RELEASE
    file += "c";
#endif
    st = new lua::State();
    Lua_Wrapper::RegisterCoreFunctions(st);
    if(st->doFile(file))
        PRINT("Loaded " + file);
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


