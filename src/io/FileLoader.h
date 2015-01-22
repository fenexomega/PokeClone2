#ifndef FILELOADER_H
#define FILELOADER_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "json/json.h"



class FileLoader
{
private:
    FileLoader();
    ~FileLoader();
public:
    static Mix_Chunk*   LoadSound(std::string path);
    static SDL_Texture* LoadTexture(std::string path);
    static Json::Value* LoadJson(std::string path);
    static TTF_Font* LoadFont(std::string path, int size);
};

#endif // FILELOADER_H
