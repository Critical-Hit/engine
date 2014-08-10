#include "ResourceManager.h"


// Global static pointer used to ensure a single instance of the class.
ResourceManager* ResourceManager::instance = NULL;

ResourceManager::~ResourceManager()
{

}

void ResourceManager::Initialize()
{
    ResourceManager::instance = new ResourceManager();
}

ResourceManager* ResourceManager::GetInstance()
{
    return ResourceManager::instance;
}

void ResourceManager::LoadTexture(int textureID, const char *fileName)
{    
    this->textureList.push_back(new Texture(textureID, fileName));
}

unsigned int ResourceManager::GetTextureUnitFromTextureID(int textureID)
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
