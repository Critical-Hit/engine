#include "Sprite.h"

Sprite::Sprite(float x, float y, float width, float height, Color color) : x(x), y(y), width(width), height(height), color(color)
{
	this->validateDimensions();
}

Sprite::Sprite(float width, float height, Color color) : x(0.0f), y(0.0f), width(width), height(height), color(color)
{
	this->validateDimensions();
}

void Sprite::MoveTo(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Sprite::MoveBy(float dx, float dy)
{
	this->x += dx;
	this->y += dy;
}

void Sprite::ChangeWidth(float width)
{
	this->width = width;
	this->validateDimensions();
}

void Sprite::ChangeHeight(float height)
{
	this->height = height;
	this->validateDimensions();
}

void Sprite::ChangeDimensions(float width, float height)
{
	this->width = width;
	this->height = height;
	this->validateDimensions();
}

void Sprite::ChangeColor(Color color)
{
	this->color = color;
}

float Sprite::GetX()
{
	return this->x;
}

float Sprite::GetY()
{
	return this->y;
}

float Sprite::GetWidth()
{
	return this->width;
}

float Sprite::GetHeight()
{
	return this->height;
}

Color Sprite::GetColor()
{
	return this->color;
}

void Sprite::validateDimensions()
{
	assert((this->width > 0) && "Sprite was given a width less than or equal to zero.");
	assert((this->height > 0) && "Sprite was given a height less than or equal to zero.");
}

bool PushVertices(float* vertexBuffer, int vertexStart, int vertexBufferSize, int* indeces, int indexStart, int indexBufferSize)
{
	return false;
}