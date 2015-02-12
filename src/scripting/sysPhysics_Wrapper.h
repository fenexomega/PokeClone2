#ifndef SYSPHYSICS_WRAPPER_H
#define SYSPHYSICS_WRAPPER_H

#include "luastate/LuaState.h"

class Rect;

class sysPhysics_Wrapper
{
protected:
    static Rect toRect(lua::Value value);
public:
    sysPhysics_Wrapper();
    static bool onScreen(lua::Value value);
    static bool onBorders(lua::Value value);
    static bool isCollidingRR(lua::Value obj1, lua::Value obj2);
    ~sysPhysics_Wrapper();
};

#endif // SYSPHYSICS_WRAPPER_H
