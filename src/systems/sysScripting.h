#ifndef SYSSCRIPTING_H
#define SYSSCRIPTING_H

#include "interfaces/iSystem.h"

class sysScripting : public iSystem
{
public:
    sysScripting();
    ~sysScripting();

    // iSystem interface
public:
    bool Init();
    void Update();
    void Dispose();
};

#endif // SYSSCRIPTING_H
