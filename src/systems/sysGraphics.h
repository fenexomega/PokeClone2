#ifndef SYSGRAPHICS_H
#define SYSGRAPHICS_H
#include "sysFlags.h"
#include "SDL2/SDL_image.h"
#include "graphics/Color.h"


extern char* SCREEN_NAME;
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern bool SCREEN_FULLSCREEN;



class sysGraphics
{
public:
    static bool Init();
    static void Shut();
    static void Update();

    //Código que devolve a textura. Todas as texturas,sons e etc devem ser colocadas na pasta Contents,
    //Essa pasta será copiada para a pasta do binário toda vez que o cmake for executado

    //Renderizar textura.
    static void renderTexture(SDL_Texture *texture, SDL_Rect rect);

    //Colore a tela inteira com a cor escolhida, inclusive o Alpha
    static void clearScreen(unsigned char r, unsigned char g, unsigned char b, unsigned char a);


};

#endif // GRAPHICS_H
