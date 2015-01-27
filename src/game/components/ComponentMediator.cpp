#include "ComponentMediator.h"

void ComponentMediator::addComponent(Component *cmp)
{
    _components.push_back(cmp);
}

ComponentMediator::ComponentMediator()
{

}

void ComponentMediator::sendMessage(int msg)
{
    for(Component* c : _components)
        if(c != nullptr)
            c->receiveMessage(msg);
}

ComponentMediator::~ComponentMediator()
{

}

