#ifndef Core_ResourceManager_h
#define Core_ResourceManager_h

#include "Texture.h"
#include <vector>
#include <memory>

using namespace std;

class ResourceManager
{
public:
    /**
     * Should NEVER be used. Only public because make_shared requires it.
     */
    ResourceManager();

    ~ResourceManager();
    
    /**
     * Initializes the ResorceManager
     */
    static void Initialize();
    
    /**
     * Retrieves the current instance of the ResourceManager.
     */
    static std::shared_ptr<ResourceManager> GetInstance();
    
    /**
     * Loads a texture with the given fileName and textureID
     *
     * @PARAM textureID
     * @PARAM fileName
     */
    void LoadTexture(int textureID, const char* fileName);
    
    /**
     * Gets the TextureUnit from the TextureID
     *
     * @PARAM textureID
     */
    unsigned int GetTextureUnitFromTextureID(int textureID);

private:
    ResourceManager(ResourceManager const &other);
    ResourceManager operator=(ResourceManager other);
    
    /**
     * The private instance of the ResourceManager. 
     */
    static std::shared_ptr<ResourceManager> instance;
    /**
     * List of Texutures
     */
    vector<std::shared_ptr<Texture>> textureList;
};

#endif
