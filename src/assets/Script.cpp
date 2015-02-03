#include "Script.h"

Script::Script(std::string fileName)
    : iAsset(AS_SCRIPT)
{
    st = sysScripting::getState();
    st->doFile(fileName);
}

lua::State &Script::getState() const
{
    return *st;
}


Script::~Script()
{

}


