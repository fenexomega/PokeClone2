#include "sysScripting.h"

#include <iostream>

#include "util/Logger.h"

sysScripting::sysScripting()
{

}

sysScripting::~sysScripting()
{

}



bool sysScripting::Init()
{
    state = new lua::State;
    state->set("x",20);
    int n = (*state)["x"];
    PRINT(n);
    return true;
}

void sysScripting::Update()
{
}

void sysScripting::Dispose()
{
    delete state;
}
