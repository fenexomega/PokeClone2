#ifndef CINPUT
#define CINPUT

#include "interfaces/iGameObject.h"
#include "game/components/Component.h"


class cInput : public Component
{
public:
    virtual void Update(iGameObject *player) = 0;
};

#endif // CINPUT

