#include "ResourceManager.h"


// Global static pointer used to ensure a single instance of the class.
std::shared_ptr<ResourceManager> ResourceManager::instance = nullptr;

ResourceManager::ResourceManager()
{
    this->textureList = std::vector<std::shared_ptr<Texture>>();
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
    if (instance == nullptr)
    {
        ResourceManager::instance = std::make_shared<ResourceManager>();
    }
    return ResourceManager::instance;
}

void ResourceManager::LoadTexture(Common::TextureId textureId)
{    
    this->textureList.push_back(std::make_shared<Texture>(textureId));
}

unsigned int ResourceManager::GetTextureUnitFromTextureID(Common::TextureId textureID)
{
    std::shared_ptr<Texture> tempTexture;
    unsigned int i;
    for (i = 0; i < this->textureList.size(); i++)
    {
        tempTexture = this->textureList[i];

        if (tempTexture->GetTextureId() == textureID)
        {
            return tempTexture->GetTextureUnit();
        }
    }

    throw new std::logic_error("A texture was used that wasn't loaded.");
}
