#ifndef RECTS_H
#define RECTS_H

#include "interfaces/iGame.h"

class Rects : public iGame
{
private:

public:
    void Init();
    void Update(float dt);
    void Draw();
    void Dispose();
};

#endif // RECTS_H
