#include "Texture.h"

Texture::Texture(int textureID, const char *fileName)
{
    this->textureID = textureID;
    this->textureUnit =  SOIL_load_OGL_texture
    (
     //"../../meeseeks.png",
     fileName,
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
    
    if(this->textureUnit == 0)
    {
        printf("Error loading Image.\n");
    }
    else
    {
        this->textureID = textureID;
    }
}

Texture::~Texture()
{

}

unsigned int Texture::GetTextureUnit()
{
    return this->textureUnit;
}

int Texture::GetTextureID()
{
    return this->textureID;
}
