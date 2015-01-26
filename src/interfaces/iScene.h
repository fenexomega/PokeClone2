#ifndef ISCENE
#define ISCENE

#include "interfaces/iGame.h"

class iScene : public iGame
{
public:
    virtual void Init(iGame *game) = 0;
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    virtual void Dispose() = 0;
};

#endif // ISCENE

