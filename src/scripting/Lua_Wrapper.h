#ifndef LUA_WRAPPER_H
#define LUA_WRAPPER_H

#include "interfaces/iGameObject.h"
#include "luastate/LuaState.h"

class Lua_Wrapper
{
friend class sysScripting;
private:
    static void RegisterCoreFunctions();
public:
    Lua_Wrapper();
    static lua::Value toLua(iGameObject *obj, std::string varName);
    static void toObj(iGameObject *obj, lua::Value objTable);
    ~Lua_Wrapper();


};

#endif // LUA_WRAPPER_H
