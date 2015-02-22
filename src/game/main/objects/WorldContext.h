#ifndef WORLDCONTEXT_H
#define WORLDCONTEXT_H

class World;

//Implemetando State Pattern

class WorldContext
{
private:
    World *_world;
public:
    WorldContext();
    ~WorldContext();
    World *world() const;
    void setWorld(World *world);

    // iGameObject interface
    void Update(float dt);
    void Render();
};

#endif // WORLDCONTEXT_H
