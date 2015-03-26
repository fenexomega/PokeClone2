#ifndef ITERACTIVEFACTORY_H
#define ITERACTIVEFACTORY_H

class IteractiveItem;
class Map;
class GameObject;
class iGameObject;
class World;
class Vector2D;

namespace Json
{
    class Value;
}

class IteractiveFactory
{
public:
    IteractiveFactory();

   static GameObject *createKey(Map *world,Json::Value json,iGameObject * player);

   static GameObject *createTeleporter(Map *world,Json::Value json,iGameObject * player,World *worldContext);

   static void changeMap(iGameObject *obj, Json::Value json);

    ~IteractiveFactory();
};

#endif // ITERACTIVEFACTORY_H
