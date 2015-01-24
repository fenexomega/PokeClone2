#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H

#include <vector>

//#include "interfaces/iComponent.h"
#include "physics/Rect.h"

typedef struct {
    int id;
}MSG;

class iGameObject
{
private:
//    std::vector<iComponent> m_components;
public:
    Rect rect;

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

//    inline void ComponentsDraw()
//    {
//        for(iComponent i : m_components)
//            i.Draw();
//    }

    virtual void SendMessage(MSG msg) = 0;
    virtual void Update(float dt) = 0;
    //TODO isso daqui deveria receber uma textura para desenhar
    virtual void Draw() = 0;

    virtual ~iGameObject() {}

};

#endif // IGAMEOBJECT_H

