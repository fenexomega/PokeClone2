#include "sysScripting.h"

#include <iostream>

#include "util/Logger.h"

#include "scripting/Lua_Wrapper.h"

lua::State* sysScripting::state;

sysScripting::sysScripting()
{

}

sysScripting::~sysScripting()
{

}

bool sysScripting::Init()
{
    state = new lua::State;
    Lua_Wrapper::RegisterCoreFunctions();
    return true;
}

void sysScripting::Update()
{
}

void sysScripting::Dispose()
{
    delete state;
}

lua::State *sysScripting::getState()
{
    return state;
}
