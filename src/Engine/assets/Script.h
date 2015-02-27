#ifndef SCRIPT_H
#define SCRIPT_H

#include "interfaces/iAsset.h"
#include "systems/sysScripting.h"

class Script : public iAsset
{
private:
    std::string file;
    lua::State *st;
public:
    //Construtor carrega o script
    Script(std::string fileName);

    //Retorna o estado do Lua
    lua::State &getState () const;

    //Recarregar o script
    void Reload();

    ~Script();
};

#endif // SCRIPT_H
