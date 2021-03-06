#include "FileLoader.h"

#include <fstream>
#include <stdexcept>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "json/json.h"
#include "graphics/Window.h"
#include "util/Logger.h"
#include "assets/Texture.h"
#include <SDL2/SDL_ttf.h>
#include "assets/Font.h"


std::map<std::string,std::shared_ptr<iAsset> > FileLoader::files;

FileLoader::FileLoader()
{

}

FileLoader::~FileLoader()
{

}

shared_ptr<Texture> FileLoader::LoadTexture(std::string path)
{
    shared_ptr<Texture> shared;
    if(files.find(path) != files.end())
    {
        shared = std::static_pointer_cast<Texture,iAsset>(files[path]);
        return shared;
    }
    SDL_Texture *texture = NULL;
    SDL_Surface *surface = IMG_Load((path).c_str());

    texture = SDL_CreateTextureFromSurface(Window::getActiveRenderer(),surface);
    SDL_FreeSurface(surface);

    if(texture == NULL)
        throw std::runtime_error("Couldn't load texture:\n " + std::string(SDL_GetError()));

    Texture *aux = new Texture(texture);
    shared = std::shared_ptr<Texture>(aux);

    files[path] = shared;
    LOG("Loaded\tImage\t" + path);


    return shared;
}

Json::Value FileLoader::LoadJson(std::string path)
{
    Json::Reader reader;
    Json::Value root = new Json::Value;
    std::ifstream file;
    LOG("Loaded\tJson\t" + path);
    file.open(path.c_str());
    if(!file.is_open())
        throw std::runtime_error("Couldn't load file " + path);

    if(reader.parse(file,root,false) == false)
    {
        LOG("Problem loading json file" + path +  " : \n"
                                 + reader.getFormattedErrorMessages());

    }

    return root;
}
shared_ptr<Font> FileLoader::LoadFont(std::string path,int size)
{

    shared_ptr<Font> shared;

    auto auxpath = path + TOSTR(size);



    if(files.find(auxpath) != files.end())
    {
        shared = std::static_pointer_cast<Font,iAsset>(files[auxpath]);
        return shared;
    }

    shared = shared_ptr<Font>(new Font);

    TTF_Font *font = TTF_OpenFont(path.c_str(),size);

    if(font == NULL)
    {
        throw std::runtime_error(SDL_GetError());
    }

    shared->m_font = font;
    shared->m_textSize = size;

    files[auxpath] = shared;
    LOG("Loaded\tFont\t" + path);

    return shared;
}

void FileLoader::Clear()
{
    for(auto i = files.begin(); i != files.end(); ++i)
            files.erase(i);


}

void FileLoader::Update()
{

    for(std::map<std::string,std::shared_ptr<iAsset> >::iterator i = files.begin(); i != files.end(); ++i)
        if(i->second.unique())
        {
            LOG("Erasing " + i->first);
            files.erase(i);
        }

}

