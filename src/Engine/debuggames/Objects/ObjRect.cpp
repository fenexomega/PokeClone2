#include "ObjRect.h"

#include "graphics/Drawer.h"
#include "systems/sysPhysics.h"

ObjRect::ObjRect(Vector2D<int> _velocity, Rect _rect,Color _color)
    : velocity(_velocity), color(_color)
{
    rect = _rect;
}

ObjRect::~ObjRect()
{

}



void ObjRect::Update(float dt)
{
    rect.x += velocity.x;
    rect.y += velocity.y;
    switch(sysPhysics::onBorders(rect))
    {
        case X_AXIS_COL:
            velocity.x = -velocity.x; break;
        case Y_AXIS_COL:
            velocity.y = -velocity.y; break;
        default:
        ;
    }

}

void ObjRect::Render()
{
    Drawer::fillRect(color,rect);
}
