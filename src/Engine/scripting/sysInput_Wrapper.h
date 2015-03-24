#ifndef SYSINPUT_WRAPPER_H
#define SYSINPUT_WRAPPER_H

#include "luastate/LuaState.h"

class sysInput_Wrapper
{
private:
    static int getValueFromString(lua::Value value);
public:
    sysInput_Wrapper();
    ~sysInput_Wrapper();
};

#endif // SYSINPUT_WRAPPER_H
