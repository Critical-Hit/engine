#ifndef Core_ResourceManager_h
#define Core_ResourceManager_h

#include "Texture.h"
#include <vector>

using namespace std;

class ResourceManager
{
public:
    
    
    ~ResourceManager();
    
    /**
     * Initializes the ResorceManager
     */
    static void Initialize();
    
    /**
     * Retrieves the current instance of the ResourceManager.
     */
    static ResourceManager* GetInstance();
    
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
    /**
     * Private contructor prevents multiple instances of the resource manager.
     */
    ResourceManager(){};
    
    ResourceManager(ResourceManager const &other);
    ResourceManager operator=(ResourceManager other);
    
    /**
     * The private instance of the ResourceManager. 
     */
    static ResourceManager* instance;
    /**
     * List of Texutures
     */
    vector<Texture*> textureList;
};

#endif
