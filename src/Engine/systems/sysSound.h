#ifndef SYSSOUND_H
#define SYSSOUND_H

#include <iostream>
#include "interfaces/iSystem.h"


class sysSound : public iSystem
{
public:
    // iSystem interface
    bool Init();
    void Update();
    void Dispose();
};

#endif // SOUND_H
