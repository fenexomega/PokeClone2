#ifndef CLICKABLE_H
#define CLICKABLE_H

#include "systems/sysInput.h"
#include "cRenderable.h"

class cClickable : public cRenderable
{
private:
    bool Draging;

    bool isClicked()
    {

    }

    bool isPress()
    {

    }

    bool isMouseOver()
    {

    }


public:
    virtual update()
    {
        isClicked();
        isPress();
        isMouseOver();
    }

    virtual bool onClick = 0;
    virtual bool onPress() = 0;
    virtual bool onMouseOver() = 0;
    virtual bool onDrag() = 0 ;
    virtual bool onDragAndDrop() = 0;
};

#endif // CLICKABLE_H
