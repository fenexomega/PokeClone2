#include "ComponentMediator.h"

#include "interfaces/iComponent.h"

void ComponentMediator::addComponent(iComponent *cmp)
{
    _components.push_back(cmp);
}

ComponentMediator::ComponentMediator()
{

}

void ComponentMediator::sendMessage(int msg)
{
    for(iComponent* c : _components)
        if(c != nullptr)
            c->receiveMessage(msg);
}

ComponentMediator::~ComponentMediator()
{

}

