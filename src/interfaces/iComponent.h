#ifndef ICOMPONENT
#define ICOMPONENT

#define COMP_GRAPHICS 1
#define COMP_PHYSICS 2
#define COMP_INPUT 3

#include "iGameObject.h"

class iComponent
{

public:


    virtual void Update(iGameObject &obj) = 0;
    virtual void Render() = 0;

    virtual ~iComponent()
    {
    }
};

#endif // ICOMPONENT

