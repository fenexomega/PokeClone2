#ifndef CZONEINPUT_H
#define CZONEINPUT_H

#include "interfaces/iComponent.h"

class cZoneInput : public iComponent
{
public:
    cZoneInput();
    ~cZoneInput();
    void Update(iGameObject &obj);
    void Draw();

    // iComponent interface

};

#endif // CINPUT_H