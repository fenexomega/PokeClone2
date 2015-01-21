#include "sysInput.h"

 const Uint8 * sysInput::keys;
 const Uint8 * sysInput::mouseKeys;

 vector<int> sysInput::mouseDownKeys;
 vector<int> sysInput::mouseUpKeys;
 vector<int> sysInput::mouseCurrentKeys;


 vector<int> sysInput::downKeys;
 vector<int> sysInput::upKeys;
 vector<int> sysInput::currentKeys;

void sysInput::update()
{
    SDL_PumpEvents();
    keys = SDL_GetKeyboardState(NULL);
    int i;
    //TODO Mouse Unput!


    mouseUpKeys.clear();
    for(i = 0; i < 4; i++)
        if(!getMouseButton(i) && (find(mouseCurrentKeys.begin(),mouseCurrentKeys.end(),i) != mouseCurrentKeys.end()) )
            mouseUpKeys.push_back(i);

    mouseDownKeys.clear();
    for(i = 0; i < 4; i++)
        if(getMouseButton(i) && !(find(mouseCurrentKeys.begin(),mouseCurrentKeys.end(),i) != mouseCurrentKeys.end()))
            mouseDownKeys.push_back(i);

    mouseCurrentKeys.clear();
    for(i = 0; i < 4; i++)
        if(getMouseButton(i))
            mouseCurrentKeys.push_back(i);



    upKeys.clear();
    for(i = 0; i < NUM_KEYCODES; i++)
        if(!getKey(i) && (find(currentKeys.begin(),currentKeys.end(),i) != currentKeys.end()) )
            upKeys.push_back(i);

    downKeys.clear();
    for(i = 0; i < NUM_KEYCODES; i++)
        if(getKey(i) && !(find(currentKeys.begin(),currentKeys.end(),i) != currentKeys.end()))
            downKeys.push_back(i);

    currentKeys.clear();
    for(i = 0; i < NUM_KEYCODES; i++)
        if(getKey(i))
            currentKeys.push_back(i);
}

bool sysInput::isKeyUp(int x)
{
    return find(upKeys.begin(),upKeys.end(),x) != upKeys.end();
}

bool sysInput::isKeyDown(int x)
{
    return find(downKeys.begin(),downKeys.end(),x) != downKeys.end();
}

bool sysInput::isKeyPressed(int x)
{
    return find(currentKeys.begin(),currentKeys.end(),x) != currentKeys.end();
}

bool sysInput::isMouseButtonUp(int x)
{
    return find(mouseUpKeys.begin(),mouseUpKeys.end(),x) != mouseUpKeys.end();
}

bool sysInput::isMouseButtonDown(int x)
{
    return find(mouseDownKeys.begin(),mouseDownKeys.end(),x) != mouseDownKeys.end();
}

bool sysInput::isMouseButtonPressed(int x)
{
    return find(mouseCurrentKeys.begin(),mouseCurrentKeys.end(),x) != mouseCurrentKeys.end();
}

bool sysInput::isAnyKeyDown()
{
    for(int i = 0; i < 300; i++)
        if(isKeyPressed(i) || isKeyDown(i))
            return true;
    return false;
}

bool sysInput::getKey(int key)
{
    return keys[key] == 1;
}

Vector2D<int> sysInput::getMousePos()
{
    int x,y;
    SDL_GetMouseState(&x,&y);
    Vector2D<int> aux(x,y);
    return aux;

}

bool sysInput::getMouseButton(int button)
{
    return SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(button);
}

//string sysInput::getText()
//{
////    std::string text(SDL_TextInputEvent.text);
////    return text;

//}
