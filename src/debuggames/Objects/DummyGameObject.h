#ifndef DUMMYGAMEOBJECT_H
#define DUMMYGAMEOBJECT_H

#include "interfaces/iGameObject.h"

class DummyGameObject : public iGameObject
{
public:
    DummyGameObject();
    ~DummyGameObject();

    // iGameObject interface
public:
    void SendMessage(MSG msg);
    void Update(float dt);
    void Draw();
};

#endif // DUMMYGAMEOBJECT_H
