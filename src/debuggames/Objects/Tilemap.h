#ifndef TILEMAP_H
#define TILEMAP_H

#include <iostream>
#include <vector>

#include "assets/Texture.h"
#include "interfaces/iGameObject.h"
#include "math/Vector2D.h"

typedef struct{
    std::vector<Uint16> data;
    Vector2D<int> size;

}Layer;

class Tilemap : public iGameObject
{
public:
    Vector2D<int> m_pos;
    Vector2D<int> m_size;
    Uint8 tileSize;
    std::vector<Texture *>m_tex;
    std::vector<Layer> layers;

    Tilemap(std::string jsonFile);
    ~Tilemap();

    // iGameObject interface
    void SendMessage(MSG msg);
    void Update(float dt);
    void Draw();
};

#endif // TILEMAP_H
