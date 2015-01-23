#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H

#include "physics/Rect.h"

typedef struct {
    int id;
}MSG;

class iGameObject
{
public:
    Rect rect;

    virtual void SendMessage(MSG msg) = 0;
    virtual void Update(float dt) = 0;
    //TODO isso daqui deveria receber uma textura para desenhar
    virtual void Draw() = 0;

    virtual ~iGameObject() {}

};

#endif // IGAMEOBJECT_H

