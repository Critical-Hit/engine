#ifndef Core_Texture_h
#define Core_Texture_h

class Texture
{
public:
	Texture();
	~Texture();

private:
	Texture operator=(Texture& other);
	Texture(Texture& other);
};

#endif