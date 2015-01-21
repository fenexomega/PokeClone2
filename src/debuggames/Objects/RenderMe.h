#ifndef RENDERME_H
#define RENDERME_H

#include "interfaces/iGameObject.h"
#include "assets/Texture.h"

class RenderMe : public iGameObject
{
private:
    Texture *texture;
public:
    RenderMe(std::string path);
    void Draw();
    void Update(float dt);

    ~RenderMe();

    // iGameObject interface
public:
    void SendMessage(MSG msg);
};

#endif // RENDERME_H