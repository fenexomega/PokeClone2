#ifndef LUA_WRAPPER_H
#define LUA_WRAPPER_H

#include "interfaces/iGameObject.h"
#include "luastate/LuaState.h"
#include "assets/Script.h"

class Lua_Wrapper
{
    static std::vector<Script *> scripts;
public:
    static void RegisterCoreFunctions(lua::State* state);

    Lua_Wrapper();
    static lua::Value toLua(Script *script,iGameObject *obj, std::string varName);
    static void toObj(iGameObject *obj, lua::Value objTable);
    static void ReloadScripts();
    static void SubscribleScript(Script * script);
    static void Unsubscrible(Script *script);
    ~Lua_Wrapper();


};

#endif // LUA_WRAPPER_H
