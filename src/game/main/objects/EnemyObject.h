#ifndef ENEMYOBJECT_H
#define ENEMYOBJECT_H

#include "interfaces/iGameObject.h"

class EnemyObject : public iGameObject
{
public:
    EnemyObject();
    ~EnemyObject();

    // iGameObject interface
    void Update(float dt);
    void Render();
};

#endif // ENEMYOBJECT_H
