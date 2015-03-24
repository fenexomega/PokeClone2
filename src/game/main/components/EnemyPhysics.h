#ifndef ENEMYPHYSICS_H
#define ENEMYPHYSICS_H

#include "components/cPhysics.h"

class EnemyPhysics : public cPhysics
{
private:
    int _velocity = 2;
    Rect _hitBox;
    iGameObject *_player;
    iGameObject *_obj;
    Map *_world;
    int _offset;
    Vector2D _v{};

    void Move(Vector2D v);
public:
    EnemyPhysics(int velocity, Rect hitBox,iGameObject *player, iComponentMediator *mediator);
    ~EnemyPhysics();

    // iComponent interface
    void receiveMessage(int msg);

    // cPhysics interface
    void Update(iGameObject *obj, Map *world, float dt);


};

#endif // ENEMYPHYSICS_H
