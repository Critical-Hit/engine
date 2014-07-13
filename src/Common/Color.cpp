#include <stdexcept>
#include "Color.h"

Color::Color(float red, float green, float blue, float alpha) : red(red), green(green), blue(blue), alpha(alpha)
{

}

Color::Color(float red, float green, float blue) : red(red), green(green), blue(blue), alpha(1.0f)
{

}

Color::Color(Color& other) : red(other.red), green(other.green), blue(other.blue), alpha(other.alpha)
{

}

Color Color::operator=(Color& other)
{
	return Color(other);
}

void Color::validateChannels()
{
	if (this->red <= 0.0f)
	{
		throw new std::invalid_argument("A color value cannot be negative.");
	}
	if (this->green <= 0.0f)
	{
		throw new std::invalid_argument("A color value cannot be negative.");
	}
	if (this->blue <= 0.0f)
	{
		throw new std::invalid_argument("A color value cannot be negative.");
	}
	if (this->alpha <= 0.0f)
	{
		throw new std::invalid_argument("A color value cannot be negative.");
	}
}