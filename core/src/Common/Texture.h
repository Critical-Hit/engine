#ifndef Core_Texture_h
#define Core_Texture_h

#include <functional>
#include "SFML/OpenGL.hpp"
#include "SFML/Graphics.hpp"
#include "ImageLoader/SOIL2.h"
#include "TextureId.h"

class Texture
{
public:
    Texture(Common::TextureId textureId);
    ~Texture();

    Texture(char* filePath);

    unsigned int GetTextureUnit();
    Common::TextureId GetTextureId();

private:
    Texture();
    Texture operator=(Texture& other);
    Texture(Texture& other);

    unsigned int textureUnit;
    Common::TextureId textureId;
};

#endif
