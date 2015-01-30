#ifndef CGRAPHIC
#define CGRAPHIC

#include "game/components/Component.h"
#include "interfaces/iGameObject.h"
#include "math/Vector2D.h"

class cGraphic : public Component
{
public:
    virtual Vector2D<int> getWidthAndHeight() = 0;
    virtual void Update(iGameObject *obj,float dt) = 0;
    virtual void Render(iGameObject *obj) = 0 ;
};


#endif // CANIMATION

