#include "ResourceManager.h"


// Global static pointer used to ensure a single instance of the class.
std::shared_ptr<ResourceManager> ResourceManager::instance = nullptr;

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{

}

void ResourceManager::Initialize()
{
    ResourceManager::instance = std::make_shared<ResourceManager>();
}

std::shared_ptr<ResourceManager> ResourceManager::GetInstance()
{
    return ResourceManager::instance;
}

void ResourceManager::LoadTexture(int textureID, const char *fileName)
{    
    this->textureList.push_back(std::make_shared<Texture>(textureID, fileName));
}

unsigned int ResourceManager::GetTextureUnitFromTextureID(int textureID)
{
    std::shared_ptr<Texture> tempTexture;
    unsigned int i;
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
