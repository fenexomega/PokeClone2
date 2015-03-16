#ifndef ACTORSFACTORY_H
#define ACTORSFACTORY_H


class GameObject;
class Map;
class Vector2D;

namespace Json
{
    class Value;
}

class ActorsFactory
{
public:
    ActorsFactory();
    static GameObject* createPlayer(Json::Value json, Map *world);
    static GameObject* createEnemy(Json::Value json, Map *world, Vector2D pos, GameObject *player);
    ~ActorsFactory();
};

#endif // ACTORSFACTORY_H
