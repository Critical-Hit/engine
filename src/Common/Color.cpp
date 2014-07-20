#include <stdexcept>
#include <string>
#include "Color.h"

Color::Color(float red, float green, float blue, float alpha) : red(red), green(green), blue(blue), alpha(alpha)
{

}

Color::Color(float red, float green, float blue) : red(red), green(green), blue(blue), alpha(1.0f)
{

}

Color::Color(const Color& other) : red(other.red), green(other.green), blue(other.blue), alpha(other.alpha)
{

}

Color Color::operator=(const Color& other)
{
	if (this != &other)
	{
		this->red = other.red;
		this->green = other.green;
		this->blue = other.blue;
		this->alpha = other.alpha;
	}
	return *this;
}

Color::~Color()
{

}

std::string Color::ToString()
{
	return "(" + std::to_string(this->red) + ", " + std::to_string(this->green) + ", " + std::to_string(this->blue) + ", " + std::to_string(this->alpha) + ")";
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