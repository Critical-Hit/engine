#include "Color.h"
#include <assert.h>

inline Color::Color(float red, float green, float blue, float alpha) : red(red), green(green), blue(blue), alpha(alpha)
{
	this->validateChannels();
}

inline Color::Color(float red, float green, float blue) : red(red), green(green), blue(blue), alpha(1.0f)
{
	this->validateChannels();
}

inline Color::Color(Color& other) : red(other.red), green(other.green), blue(other.blue), alpha(other.alpha)
{
	
}

inline Color Color::operator=(Color& other)
{
	return Color(other.red, other.green, other.blue, other.alpha);
}

void inline Color::validateChannels()
{
	assert((this->red < 0) && "The red channel was set to a value less than zero.");
	assert((this->green < 0) && "The green channel was set to a value less than zero.");
	assert((this->blue < 0) && "The blue channel was set to a value less than zero.");
	assert((this->alpha < 0) && "The alpha channel was set to a value less than zero.");
}