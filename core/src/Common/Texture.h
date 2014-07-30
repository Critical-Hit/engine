#ifndef Core_Texture_h
#define Core_Texture_h


#include <ImageLoader/SOIL2.h>
#include <GLFW/glfw3.h>
#include <functional>

class Texture
{
public:
	Texture();
	~Texture();
    
    Texture(char* filePath);
    
    GLuint GetTextureID();


private:
	Texture operator=(Texture& other);
	Texture(Texture& other);
    
    GLuint textureID;
};


#endif