#ifndef SYSSCRIPTING_H
#define SYSSCRIPTING_H

#include "interfaces/iSystem.h"
#include "luastate/LuaState.h"

class sysScripting : public iSystem
{
private:
    static lua::State *state;
public:
    sysScripting();
    ~sysScripting();

    // iSystem interface
    bool Init();
    void Update();
    void Dispose();

    static lua::State* getState();
};

#endif // SYSSCRIPTING_H
