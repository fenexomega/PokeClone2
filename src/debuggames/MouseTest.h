#ifndef MOUSETEST_H
#define MOUSETEST_H

#include "interfaces/iGame.h"
#include "Objects/RenderMe.h"


class MouseTest : public iGame
{
private:
    bool squares[3];
    RenderMe *mouse;
public:
    void Init();
    void Update(float dt);
    void Draw();
    void Dispose();
};

#endif // MOUSETEST_H
