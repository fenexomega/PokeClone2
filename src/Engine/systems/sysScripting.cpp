#include "sysScripting.h"

#include <iostream>


#include "util/Logger.h"

#include "scripting/Lua_Wrapper.h"
#include "systems/sysInput.h"

sysScripting::sysScripting()
{

}

sysScripting::~sysScripting()
{

}

bool sysScripting::Init()
{

    return true;
}

void sysScripting::Update()
{
#ifndef RELEASE
    if(sysInput::isKeyDown(SDL_SCANCODE_F5))
        Lua_Wrapper::ReloadScripts();
#endif
}

void sysScripting::Dispose()
{
}

