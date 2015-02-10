#ifndef LUA_WRAPPER_H
#define LUA_WRAPPER_H

#include "luastate/LuaState.h"
class iGameObject;
class Script;

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

    static bool onScreen(lua::Value value);
    ~Lua_Wrapper();


};

#endif // LUA_WRAPPER_H
