#ifndef SCRIPT_H
#define SCRIPT_H

#include "interfaces/iAsset.h"

#include "systems/sysScripting.h"


class Script : public iAsset
{
private:
    lua::State *st;
public:
    Script(std::string fileName);
    lua::State &getState () const;
    ~Script();
};

#endif // SCRIPT_H
