#ifndef BUTTON_H
#define BUTTON_H

#include <vector>

#include "interfaces/iCommand.h"
#include "assets/Texture.h"
#include "assets/Font.h"

class Button
{   
public:
    enum
    {
        STATE_NORMAL,
//        STATE_ON_PRESS,
        STATE_MOUSE_OVER,
        STATE_NUMBERS

    };

    Button(int x, int y, std::shared_ptr<Texture>normal,
           std::shared_ptr<Texture>mouseOver, iCommand* command ,
           Font *font, std::string text, Color text_color);
    void RegisterCommand(iCommand* command);
    ~Button();

    // iComponent interface
    void Update();
    void Render();
private:
    iCommand *command{};
    std::vector<std::shared_ptr<Texture> > textures;
    Rect rect;
    int state{};
    Font *m_font{};
    std::shared_ptr<Texture> m_text_tex;
    std::string m_text;
};

#endif // BUTTON_H
