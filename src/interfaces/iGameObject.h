#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H

#include <vector>

//#include "interfaces/iComponent.h"
#include "physics/Rect.h"

class iGameObject
{
private:
//    std::vector<iComponent> m_components;
public:
    Rect rect;
    Vector2D<int> pos;
    Vector2D<int> acc;



//    inline void ComponentAdd(iComponent c)
//    {
//        m_components.push_back(c);
//    }

//    inline iComponent ComponentRemove(int i)
//    {
//        iComponent aux = m_components.at(i);
//        m_components.erase(m_components.begin() + i);

//        return aux;
//    }

//    inline void ComponentsUpdate()
//    {
//        for(iComponent i : m_components)
//            i.Update(this);
//    }

//    inline void ComponentsRender()
//    {
//        for(iComponent i : m_components)
//            i.Render();
//    }

//    virtual void SendMessage(MSG msg) = 0;
    virtual void Update(float dt) = 0;
    //TODO isso daqui deveria receber uma textura para desenhar
    virtual void Render() = 0;

    virtual ~iGameObject() {}

};

#endif // IGAMEOBJECT_H

