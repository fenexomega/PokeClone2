#ifndef SYSSCRIPTING_H
#define SYSSCRIPTING_H

#include "interfaces/iSystem.h"
#include "luastate/LuaState.h"


class sysScripting : public iSystem
{
private:
    lua::State *state;
public:
    sysScripting();
    ~sysScripting();

    // iSystem interface
    bool Init();
    void Update();
    void Dispose();
};

#endif // SYSSCRIPTING_H
