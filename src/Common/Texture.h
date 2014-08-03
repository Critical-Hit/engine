#ifndef Core_Texture_h
#define Core_Texture_h


#include <ImageLoader/SOIL2.h>
#include <GLFW/glfw3.h>
#include <functional>

class Texture
{
public:
	Texture(int textureID, const char *fileName);
	~Texture();
    
    Texture(char* filePath);
    
    GLuint GetTextureUnit();
    int GetTextureID();


private:
    Texture();
	Texture operator=(Texture& other);
	Texture(Texture& other);
    
    GLuint textureUnit;
    int textureID;
};


#endif