#ifndef TELEPORTERPHYSICS_H
#define TELEPORTERPHYSICS_H

#include "components/cPhysics.h"

class World;

class TeleporterPhysics : public cPhysics
{
private:
    iGameObject *_player;
    std::string _mapName{};
    Vector2D _mapPos{};
    World *_wc;
public:
    TeleporterPhysics(iComponentMediator *mediator, iGameObject *player,
                      World *wc);
    ~TeleporterPhysics();

    // iComponent interface
    void receiveMessage(int msg);

    // cPhysics interface
    void Update(iGameObject *obj, Map *world, float dt);
    void setMapToTeleport(const std::string mapName, const Vector2D mapPos);
};

#endif // TELEPORTERPHYSICS_H
