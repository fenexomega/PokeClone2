#ifndef MOUSETEST_H
#define MOUSETEST_H

#include "interfaces/iGame.h"


class MouseTest : public iGame
{
private:
    bool squares[3];
public:
    void Init();
    void Update(float dt);
    void Render();
    void Dispose();
};

#endif // MOUSETEST_H
