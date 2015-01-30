#ifndef OBJRECT_H
#define OBJRECT_H

#include "interfaces/iGameObject.h"
#include "graphics/Color.h"

class ObjRect : public iGameObject
{
public:
    ObjRect(Vector2D<int> _velocity, Rect _rect, Color _color);
    ~ObjRect();
    Vector2D<int> velocity;
    Color color;
    // iGameObject interface
    void Update(float dt);
    void Render();
};

#endif // OBJRECT_H
