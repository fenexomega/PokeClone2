#include "FileLoader.h"

#include <fstream>
#include <SDL2/SDL_image.h>

#include "json/json.h"
#include "graphics/Window.h"
#include "gSettings.h"

FileLoader::FileLoader()
{

}

FileLoader::~FileLoader()
{

}

SDL_Texture* FileLoader::LoadTexture(std::string path)
{
    SDL_Texture *texture = NULL;
    SDL_Surface *surface = IMG_Load((path).c_str());
    //SDL_SetColorKey(surface,SDL_TRUE,SDL_MapRGB(surface->format,GALPHA_COLOR));

    texture = SDL_CreateTextureFromSurface(Window::getActiveRenderer(),surface);
    if(texture == NULL)
    {
                std::cerr << "ERROR: " << SDL_GetError() << std::endl;
    }
    SDL_FreeSurface(surface);
    return texture;
}

Json::Value* FileLoader::LoadJson(std::string path)
{
    Json::Reader reader;
    Json::Value *root = new Json::Value;
    std::ifstream file;
    file.open(path.c_str());
    if(!file.is_open())
        ;

    if(reader.parse(file,*root,false) == false)
        ; //LOG ERROR reader.gerFormattedErrorMessages()

    return root;
}
TTF_Font* FileLoader::LoadFont(std::string path,int size)
{
    TTF_Font *font = TTF_OpenFont(path.c_str(),size);
    if(font == nullptr)
    {
        std::cerr << SDL_GetError() << std::endl;
        return nullptr;
    }
    return font;

}

