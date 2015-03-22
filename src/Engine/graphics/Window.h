#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <iostream>

class Window
{
private:
    static SDL_Window *SDLwindow;
    static SDL_Renderer *SDLrenderer;
    static int width, height;
    static SDL_Texture *finalScreen;
    static std::string title;
    static SDL_Event PollEvent();

public:
    Window(int width, int height, std::string title, bool isFullscreen = false);
    ~Window();

    static SDL_Renderer *getActiveRenderer();

    void SwapBuffers();
    bool UserWannaQuit();
    void Destroy();
    void Update();

    static void setGrabMouse(bool value);
    static void setHiddenMouseCursor(bool value);
    static void TakeShot();
    static void appendTitle(std::string st);
    static void clearScreen(uint8_t r, uint8_t g, uint8_t b,uint8_t a);
    static int getWidth();
    static void setWidth(int value);
    static int getHeight();
    static void setHeight(int value);

};

#endif // WINDOW_H
