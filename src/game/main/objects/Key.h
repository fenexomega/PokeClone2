#ifndef KEY_H
#define KEY_H

#include "interfaces/iGameObject.h"

class Key : public iGameObject
{
public:
    Key();
    ~Key();

    // iGameObject interface
    void Update(float dt);
    void Render();
};

#endif // KEY_H
