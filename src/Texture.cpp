#include "Texture.h"


Texture::Texture()
{
    this->textureID =  SOIL_load_OGL_texture
    (
     "meeseeks.png",
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
    
    if(this->textureID == 0)
    {
        printf("Error loading Image.\n");
    }
    else
    {
        printf("Image load successfull.\n");
    }
}

Texture::~Texture()
{

}

GLuint Texture::GetTextureID()
{
    return this->textureID;
}
