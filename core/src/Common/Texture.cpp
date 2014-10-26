#include "Texture.h"
#include "TextureIdUtils.h"

Texture::Texture(Common::TextureId textureId)
{
    sf::Image image;
    image.loadFromFile(View::TextureIdUtils::GetTexturePath(textureId));
    
    GLuint textureUnit;
    glGenTextures(1, &textureUnit);
    glBindTexture(GL_TEXTURE_2D, textureUnit);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
    this->textureUnit = textureUnit;

    if(this->textureUnit == 0)
    {
        throw new std::logic_error("Error loading texture file.");
    }
    this->textureId = textureId;
}

Texture::~Texture()
{

}

unsigned int Texture::GetTextureUnit()
{
    return this->textureUnit;
}

Common::TextureId Texture::GetTextureId()
{
    return this->textureId;
}
