#ifndef FILELOADER_H
#define FILELOADER_H

#include <iostream>
#include <SDL2/SDL_ttf.h>

#include "json/json.h"
#include "assets/Texture.h"



class FileLoader
{
private:
    FileLoader();
    ~FileLoader();
public:
    static SDL_Texture *LoadTexture(std::string path);
    static Json::Value* LoadJson(std::string path);
    static TTF_Font* LoadFont(std::string path, int size);
};

#endif // FILELOADER_H
