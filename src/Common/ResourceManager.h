#ifndef Core_ResourceManager_h
#define Core_ResourceManager_h

#include "Texture.h"
#include <vector>

using namespace std;

class ResourceManager
{
public:
    
    ResourceManager();
    ~ResourceManager();
    
    //Initializes the ResorceManager
    void Initialize();
    
    //Loads a texture with the given fileName and textureID
    void LoadTexture(int textureID, char* fileName);
    
    //Gets the TextureUnit from the TextureID
    GLuint GetTextureUnitFromTextureID(int textureID);

private:
    
    // Private constructors to disallow access.
    ResourceManager(ResourceManager const &other);
    ResourceManager operator=(ResourceManager other);
    
    //Singleton of the ResourceManager
    ResourceManager* instance;
    
    //List of Texutures
    vector<Texture*> textureList;
};

#endif