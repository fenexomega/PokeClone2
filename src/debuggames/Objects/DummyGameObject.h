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
    void Update(float dt);
    void Render();
};

#endif // DUMMYGAMEOBJECT_H
