#ifndef COMPONENTMEDIATOR_H
#define COMPONENTMEDIATOR_H

#include <vector>
#include "game/components/Component.h"

class ComponentMediator
{
public:
    std::vector <Component *> _components;

    void addComponent(Component *cmp);
    ComponentMediator();
    void sendMessage(int msg);
    ~ComponentMediator();
};

#endif // COMPONENTMEDIATOR_H
