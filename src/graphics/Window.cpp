#include "Window.h"

SDL_Window *Window::SDLwindow;
SDL_Renderer *Window::SDLrenderer;
int Window::width;
int Window::height;
std::string Window::title;


int Window::getWidth()
{
    return width;
}

void Window::setWidth(int value)
{
    width = value;
}

int Window::getHeight()
{
    return height;
}

void Window::setHeight(int value)
{
    height = value;
}

Window::~Window()
{

}

SDL_Renderer* Window::getActiveRenderer()
{
    return SDLrenderer;
}

void Window::SwapBuffers()
{
    SDL_RenderPresent(SDLrenderer);
}

bool Window::UserWannaQuit()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    return e.type == SDL_QUIT;
}

void Window::Destroy()
{
    SDL_DestroyRenderer(SDLrenderer);
    SDL_DestroyWindow(SDLwindow);
}

void Window::appendTitle(std::string st)
{
    SDL_SetWindowTitle(SDLwindow,(title + st).c_str());
}

void Window::clearScreen(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_SetRenderDrawColor(SDLrenderer,r,g,b,a);
    SDL_RenderClear(SDLrenderer);
}

Window::Window(int _width, int _height, std::string title, bool isFullscreen )
{
    static int windowsFlags = SDL_WINDOW_SHOWN  ;
    if(SDLwindow)
    {
        SDL_DestroyWindow(SDLwindow);
        SDL_DestroyRenderer(SDLrenderer);
    }
    this->width = _width;
    this->height = _height;
    this->title = title;

    if(isFullscreen)
        windowsFlags |= SDL_WINDOW_FULLSCREEN_DESKTOP;

    SDLwindow = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED
                                 ,SDL_WINDOWPOS_CENTERED,width,height,
                                 windowsFlags);
   SDLrenderer =  SDL_CreateRenderer(SDLwindow,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(SDLwindow == NULL || SDLrenderer == NULL)
        std::cout << "DEU MERDA" << std::endl; // TODO tratar isso

}



