#ifndef CTILEMAPINPUT_H
#define CTILEMAPINPUT_H

#include "interfaces/iComponent.h"

class cTileMapInput : public iComponent
{
public:
    cTileMapInput();
    ~cTileMapInput();

    // iComponent interface
public:
    void Update(iGameObject &obj);
    void Draw();
};

#endif // CTILEMAPINPUT_H