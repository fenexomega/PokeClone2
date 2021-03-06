#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H

#include <vector>

//#include "interfaces/iComponent.h"
#include "physics/Rect.h"
#include "components//ComponentMediator.h"

class iGameObject
{
//    std::vector<iComponent> m_components;
private:
    ComponentMediator _mediator;

public:
    std::string name;
    std::string type;
    bool _active = true;

    Rect rect;
    Vector2D pos;
    Vector2D acc;

    virtual void Update(float dt) = 0;
    virtual void Render() = 0;

    virtual ~iGameObject() {}



    void SendMessage(int msg)
    {
        _mediator.sendMessage(msg);
    }

    ComponentMediator* const mediator()
    {
        return &_mediator;
    }

    void setMediator(const ComponentMediator &mediator)
    {
        _mediator = mediator;
    }

};




#endif // IGAMEOBJECT_H



