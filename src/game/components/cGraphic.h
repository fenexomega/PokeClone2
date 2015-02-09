#ifndef CGRAPHIC
#define CGRAPHIC

#include "interfaces/iComponent.h"
#include "interfaces/iGameObject.h"
#include "math/Vector2D.h"
#include "components/MessageSender.h"

class cGraphic : public iComponent
{
public:
    cGraphic(iComponentMediator *mediator)
        : iComponent(mediator){}
    virtual void Update(iGameObject *obj,float dt) {}
    virtual void Render(iGameObject *obj) {}
};


#endif // CANIMATION
