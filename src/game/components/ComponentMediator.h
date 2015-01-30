#ifndef COMPONENTMEDIATOR_H
#define COMPONENTMEDIATOR_H

#include <vector>
#include "interfaces/iComponent.h"

class ComponentMediator
{
public:
    std::vector <iComponent *> _components;

    void addComponent(iComponent *cmp);
    ComponentMediator();
    void sendMessage(int msg);
    ~ComponentMediator();
};

#endif // COMPONENTMEDIATOR_H
