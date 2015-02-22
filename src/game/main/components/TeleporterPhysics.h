#ifndef TELEPORTERPHYSICS_H
#define TELEPORTERPHYSICS_H

#include "game/components/cPhysics.h"

class WorldContext;

class TeleporterPhysics : public cPhysics
{
private:
    iGameObject *_player;
    std::string _map;
    Vector2D<int> _mapPos;
    WorldContext *_wc;
public:
    TeleporterPhysics(iComponentMediator *mediator,iGameObject *player,
                      WorldContext *wc,std::string newMap,Vector2D<int> mapPos);
    ~TeleporterPhysics();

    // iComponent interface
    void receiveMessage(int msg);

    // cPhysics interface
    void Update(iGameObject *obj, World *world, float dt);
};

#endif // TELEPORTERPHYSICS_H
