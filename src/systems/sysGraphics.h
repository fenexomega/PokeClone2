#ifndef SYSGRAPHICS_H
#define SYSGRAPHICS_H

#include "interfaces/iSystem.h"

class sysGraphics : public iSystem
{
public:
    bool Init();
    void Update();
    void Dispose();
};

#endif // GRAPHICS_H
