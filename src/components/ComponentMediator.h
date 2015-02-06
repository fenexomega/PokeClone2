#ifndef COMPONENTMEDIATOR_H
#define COMPONENTMEDIATOR_H

#include <vector>
#include "interfaces/iComponentMediator.h"

class ComponentMediator : public iComponentMediator
{
public:
    std::vector <iComponent *> _components;

    void addComponent(iComponent *cmp);
    ComponentMediator();
    void sendMessage(int msg);
    ~ComponentMediator();
};

#endif // COMPONENTMEDIATOR_H
