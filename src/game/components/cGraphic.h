#ifndef CGRAPHIC
#define CGRAPHIC

#include "game/components/Component.h"
#include "interfaces/iGameObject.h"

class cGraphic : public Component
{
public:
    virtual void Update(iGameObject *obj,float dt) = 0;
    virtual void Render(iGameObject *obj) = 0 ;
};


#endif // CANIMATION

