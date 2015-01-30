#ifndef PHYSICSTEST_H
#define PHYSICSTEST_H

#include <vector>

#include "interfaces/iGame.h"
#include "debuggames/Objects/ObjRect.h"


class PhysicsTest : public iGame
{
private:
    std::vector<ObjRect *>rects;
public:
    PhysicsTest();
    ~PhysicsTest();

    // iGame interface
    void Init();
    void Update(float dt);
    void SendMessage(MSG msg);
    void Render();
    void Dispose();
};

#endif // PHYSICSTEST_H
