#include "Texture.h"


Texture::Texture(int textureID, char* fileName)
{
    this->textureID =  SOIL_load_OGL_texture
    (
     fileName,
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
        this->textureID = textureID;
    }
}

Texture::~Texture()
{

}

GLuint Texture::GetTextureUnit()
{
    return this->textureUnit;
}

int Texture::GetTextureID()
{
    return this->textureID;
}
