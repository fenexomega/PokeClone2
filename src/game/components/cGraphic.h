#ifndef CGRAPHIC
#define CGRAPHIC

#include "interfaces/iComponent.h"
#include "interfaces/iGameObject.h"
#include "math/Vector2D.h"

class cGraphic : public iComponent
{
public:
    virtual Vector2D<int> getWidthAndHeight() { return Vector2D<int>();}
    virtual void Update(iGameObject *obj,float dt) {}
    virtual void Render(iGameObject *obj) {}
};


#endif // CANIMATION

