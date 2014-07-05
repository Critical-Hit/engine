#include <assert.h>
#include "Sprite.h"

inline Sprite::Sprite(float x, float y, float width, float height, Color color) : x(x), y(y), width(width), height(height), color(color)
{
	this->validateDimensions();
}

void inline Sprite::MoveTo(float x, float y)
{
	this->x = x;
	this->y = y;
}

void inline Sprite::MoveBy(float dx, float dy)
{
	this->x += dx;
	this->y += dy;
}

void inline Sprite::ChangeWidth(float width)
{
	this->width = width;
	this->validateDimensions();
}

void inline Sprite::ChangeHeight(float height)
{
	this->height = height;
	this->validateDimensions();
}

void inline Sprite::ChangeDimensions(float width, float height)
{
	this->width = width;
	this->height = height;
	this->validateDimensions();
}

void inline Sprite::ChangeColor(Color color)
{
	this->color = color;
}

float inline Sprite::GetX()
{
	return this->x;
}

float inline Sprite::GetY()
{
	return this->y;
}

float inline Sprite::GetWidth()
{
	return this->width;
}

float inline Sprite::GetHeight()
{
	return this->height;
}

Color inline Sprite::GetColor()
{
	return this->color;
}

void inline Sprite::validateDimensions()
{
	assert((this->width > 0) && "Sprite was given a width less than or equal to zero.");
	assert((this->height > 0) && "Sprite was given a height less than or equal to zero.");
}