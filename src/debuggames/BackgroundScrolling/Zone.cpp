#include "Zone.h"

void Zone::addComponent(shared_ptr<iComponent> ptr)
{
    components.push_back(ptr);
}

void Zone::removeComponent(unsigned int at)
{
    components.erase(components.begin() + at);
}

Zone::Zone()
{

}

Zone::~Zone()
{

}


void Zone::Update(float dt)
{
    for(auto i : components) {
//        i->Update(*this);
    }
}

void Zone::Render()
{
    for(auto i : components) {
//        i->Render();
    }
}

