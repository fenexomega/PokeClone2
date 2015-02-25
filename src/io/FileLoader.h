#ifndef FILELOADER_H
#define FILELOADER_H

#include <iostream>
#include <memory>
#include <SDL2/SDL_ttf.h>
#include <map>

#include "json/json.h"

class Texture;
class iAsset;

using std::shared_ptr;


//TODO usar um flyweight para passar assets
class FileLoader
{
private:
    FileLoader();
    ~FileLoader();
    static std::map<std::string,std::shared_ptr<iAsset> > files;
public:
    //TODO usar Flyweights
//    static Mix_Chunk*   LoadSound(std::string path);
    static shared_ptr<Texture> LoadTexture(std::string path);
    static Json::Value LoadJson(std::string path);
    static TTF_Font* LoadFont(std::string path, int size);
    static void Clear();
    static void Update();
};

#endif // FILELOADER_H
