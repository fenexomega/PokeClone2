#ifndef LOGGER_WRAPPER_H
#define LOGGER_WRAPPER_H

#include "luastate/LuaState.h"

class Logger_Wrapper
{
public:
    Logger_Wrapper();
    static void LOG(lua::Value stg);
    ~Logger_Wrapper();
};

#endif // LOGGER_WRAPPER_H
