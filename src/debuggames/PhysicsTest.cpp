#include "PhysicsTest.h"

#include "util/uRandom.h"

#include "systems/sysPhysics.h"

PhysicsTest::PhysicsTest()
{

}

PhysicsTest::~PhysicsTest()
{

}



void PhysicsTest::Init()
{
    for(int i = 0; i < 10;++i)
    {
        rects.push_back(new ObjRect(Vector2D<int>(uRandom::getInt(2)+1,uRandom::getInt(2)+1),
                                    Rect(uRandom::getInt(800),uRandom::getInt(800),64,64),
                                    Color(uRandom::getInt(255),uRandom::getInt(255),uRandom::getInt(255),255)));
    }
}

void PhysicsTest::Update(float dt)
{
    for(auto i : rects)
        i->Update(dt);
    for(auto i : rects)
        for(auto z : rects)
            if(sysPhysics::isColliding(i->rect,z->rect))
            {
                i->velocity = -i->velocity;
                z->velocity = -z->velocity;

            }
}

void PhysicsTest::SendMessage(MSG msg)
{
}

void PhysicsTest::Render()
{
    for(auto i : rects)
        i->Render();
}

void PhysicsTest::Dispose()
{
}
