#ifndef CINPUT
#define CINPUT

#include "interfaces/iGameObject.h"

class cInput
{
public:
    virtual void Update(iGameObject *player) = 0;
};

#endif // CINPUT

