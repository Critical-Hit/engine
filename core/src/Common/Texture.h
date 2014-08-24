#ifndef Core_Texture_h
#define Core_Texture_h

#include <functional>
#include "ImageLoader/SOIL2.h"

class Texture
{
public:
	Texture(int textureID, const char *fileName);
	~Texture();
    
    Texture(char* filePath);
    
    unsigned int GetTextureUnit();
    int GetTextureID();


private:
    Texture();
	Texture operator=(Texture& other);
	Texture(Texture& other);
    
    unsigned int textureUnit;
    int textureID;
};


#endif
