#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
    
}

ResourceManager::~ResourceManager()
{

}

void ResourceManager::Initialize()
{
    this->instance = new ResourceManager();
}

void ResourceManager::LoadTexture(int textureID, char *fileName)
{
    Texture* texture = new Texture(textureID, fileName);
    
    this->textureList.push_back(texture);
}

GLuint ResourceManager::GetTextureUnitFromTextureID(int textureID)
{
    Texture* tempTexture;
    int i;
    for(i = 0; i < this->textureList.size(); i++)
    {
        tempTexture = this->textureList[i];
        
        if(tempTexture->GetTextureID() == textureID)
        {
            return tempTexture->GetTextureUnit();
        }
    }
    
    return 0;
}