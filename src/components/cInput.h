#ifndef CINPUT_H
#define CINPUT_H

#include "interfaces/iComponent.h"

class cInput : public iComponent
{
public:
    static const int id = COMP_INPUT;
    cInput();
    ~cInput();
    void Update(iGameObject &obj);
    void Render();

    // iComponent interface

};

#endif // CINPUT_H
