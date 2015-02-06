#ifndef SYSINPUT_H
#define SYSINPUT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include "math/Vector2D.h"

using namespace std;


#define NUM_KEYCODES 512



class sysInput
{
private:
    static const Uint8 * keys;
    static const Uint8 * mouseKeys;

    static vector<int> mouseDownKeys;
    static vector<int> mouseUpKeys;
    static vector<int> mouseCurrentKeys;


    static vector<int> downKeys;
    static vector<int> upKeys;
    static vector<int> currentKeys;
public:
    static void update();

    static bool isKeyUp(int x);

    static bool isKeyDown(int x);

    static bool isKeyPressed(int x);

    static bool isMouseButtonUp(int x);

    static bool isMouseButtonDown(int x);

    static bool isMouseButtonPressed(int x);

    static bool isAnyKeyDown();

    static int getKeyDown();

    static int getKeyPressed();

    static bool getKey(int key);

    static Vector2D<int> getMousePos();

    static bool getMouseButton(int button);

//    static std::string getText();

};
#endif // INPUT_H
