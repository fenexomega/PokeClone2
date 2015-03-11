#ifndef RECTSTEST_H
#define RECTSTEST_H

#include "interfaces/iGame.h"

class RectsTests : public iGame
{
private:

public:
    void Init();
    void Update(float dt);
    void Render();
    void Dispose();
};

#endif // RECTS_H
