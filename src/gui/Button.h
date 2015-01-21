#ifndef BUTTON_H
#define BUTTON_H

#include <vector>

#include "interfaces/iComponent.h"
#include "interfaces/iCommand.h"
#include "assets/Texture.h"


class Button : public iComponent
{   
public:
    enum
    {
        STATE_NORMAL,
//        STATE_ON_PRESS,
        STATE_MOUSE_OVER,
        STATE_NUMBERS

    };

    Button(int x, int y, Texture *normal,Texture *mouseOver,iCommand* command);
    void RegisterCommand(iCommand* command);
    ~Button();

    // iComponent interface
    void Update(iGameObject &obj);
    void Draw();
private:

    iCommand *command;
    std::vector<Texture *> textures;
    Rect rect;
    int state;
};

#endif // BUTTON_H
