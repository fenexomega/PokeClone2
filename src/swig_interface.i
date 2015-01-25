%module PokeClone
%include <std_string.i>
%include <std_vector.i>
%include <std_shared_ptr.i>
%include <typemaps.i>
%{
    #include "interfaces/iGameObject.h"
    #include "interfaces/iAsset.h"
    #include "interfaces/iGame.h"
    #include "interfaces/iSystem.h"
    #include "interfaces/iCommand.h"
    #include "interfaces/iComponent.h"
    #include "math/Vector2D.h"
    #include "graphics/Window.h"
    #include "graphics/Color.h"
    #include "graphics/Drawer.h"
    #include "graphics/extra/Tilemap.h"
    #include "components/cMovable.h"
    #include "components/cInput.h"
    #include "components/cRenderable.h"
    #include "components/cPositionable.h"
    #include "components/cAudible.h"
    #include "components/Graphics/cTextures.h"
    #include "components/cClickable.h"
    #include "assets/Sound.h"
    #include "assets/Text.h"
    #include "assets/Texture.h"
    #include "gui/Button.h"
    #include "physics/Rect.h"
    #include "io/FileLoader.h"
    #include "io/CacheHelper.h"
    #include "Engine.h"
    #include "systems/sysPhysics.h"
    #include "systems/sysFlags.h"
    #include "systems/sysInput.h"
    #include "systems/sysSound.h"
    #include "systems/sysGraphics.h"
    #include "util/Logger.h"
    #include "util/uTime.h"
    #include "util/uRandom.h"
//    #include "game/Game.h"

%}
int Engine::Run(iGame *INPUT);
//using namespace std;
%template(VecFloat) std::vector< float >;
%template(VecInt) std::vector< int >;

%include "interfaces/iGameObject.h"
%include "interfaces/iAsset.h"
%include "interfaces/iGame.h"
%include "interfaces/iSystem.h"
%include "interfaces/iCommand.h"
%include "interfaces/iComponent.h"
%include "math/Vector2D.h"
%include "graphics/Window.h"
%include "graphics/Color.h"
%include "graphics/Drawer.h"
%include "graphics/extra/Tilemap.h"
%include "components/cMovable.h"
%include "components/cInput.h"
%include "components/cRenderable.h"
%include "components/cPositionable.h"
%include "components/cAudible.h"
%include "components/Graphics/cTextures.h"
%include "components/cClickable.h"
%include "assets/Sound.h"
%include "assets/Text.h"
%include "assets/Texture.h"
%include "gui/Button.h"
%include "physics/Rect.h"
%include "io/FileLoader.h"
%include "io/CacheHelper.h"
%include "Engine.h"
%include "systems/sysPhysics.h"
%include "systems/sysFlags.h"
%include "systems/sysInput.h"
%include "systems/sysSound.h"
%include "systems/sysGraphics.h"
%include "util/Logger.h"
%include "util/uTime.h"
%include "util/uRandom.h"

//%include "game/Game.h"

%typemap(in) iGame * {
    $result = *iGame;
}
