#include "sysScripting.h"

#include <Python.h>
#include "util/Logger.h"

sysScripting::sysScripting()
{

}

sysScripting::~sysScripting()
{

}



bool sysScripting::Init()
{
    Py_Initialize();
    PRINT(Py_GetVersion());
    return true;
}

void sysScripting::Update()
{

}

void sysScripting::Dispose()
{
    Py_Finalize();
}
