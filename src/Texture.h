#ifndef Core_Texture_h
#define Core_Texture_h


#include <ImageLoader/SOIL2.h>



class Texture
{
public:
	Texture();
	~Texture();
    
    Texture(char* filePath);

private:
	Texture operator=(Texture& other);
	Texture(Texture& other);
};

#endif