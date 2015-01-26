#ifndef ZONE_H
#define ZONE_H

#include <vector>
#include <memory>

#include "interfaces/iGameObject.h"
#include "interfaces/iComponent.h"

using std::vector;
using std::shared_ptr;

class Zone : public iGameObject
{
private:
    vector<shared_ptr<iComponent> > components;
public:
    void addComponent(shared_ptr<iComponent> ptr);
    void removeComponent(unsigned int at);

    Zone();
    ~Zone();

    // iGameObject interface
public:
    void Update(float dt);
    void Render();

    // iGameObject interface
};

#endif // ZONE_H
