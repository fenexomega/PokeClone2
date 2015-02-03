#include "FileLoader.h"

#include <fstream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "json/json.h"
#include "graphics/Window.h"
#include "gSettings.h"


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

    //TODO throw exception
    if(texture == NULL)
    {
        std::cerr << "ERROR: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    Texture *aux = new Texture(texture);
    shared = std::shared_ptr<Texture>(aux);

    files[path] = shared;

    return shared;
}

Json::Value FileLoader::LoadJson(std::string path)
{
    Json::Reader reader;
    Json::Value root = new Json::Value;
    std::ifstream file;
    file.open(path.c_str());
    if(!file.is_open())
        std::cerr << "Não conseguiu abrir" << std::endl;

    if(reader.parse(file,root,false) == false)
        std::cerr << "Problema no json" << std::endl; //LOG ERROR reader.gerFormattedErrorMessages()

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

void FileLoader::Update()
{
    for(auto i = files.begin(); i != files.end(); ++i)
    {
        if(i->second.unique())
            files.erase(i);
    }
}

