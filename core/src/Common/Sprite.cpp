#include <stdexcept>
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
	if (this->width < 0)
	{
		throw new std::invalid_argument("Sprite was given a width less than or equal to zero.");
	}
	if (this->height < 0)
	{
		throw new std::invalid_argument("Sprite was given a height less than or equal to zero.");
	}
}

void Sprite::PutGLVertexInfo(float* vertexBuffer)
{
	float left = x;
	float right = x + width;
	float top = y;
	float bottom = y - height;
	// Top/Left
	vertexBuffer[0] = left;
	vertexBuffer[1] = top;
	vertexBuffer[2] = 0.0f;
	vertexBuffer[3] = 1.0f;
	// Top/Right
	vertexBuffer[4] = right;
	vertexBuffer[5] = top;
	vertexBuffer[6] = 0.0f;
	vertexBuffer[7] = 1.0f;
	// Bottom/Right
	vertexBuffer[8] = right;
	vertexBuffer[9] = bottom;
	vertexBuffer[10] = 0.0f;
	vertexBuffer[11] = 1.0f;
	// Bottom/Left
	vertexBuffer[12] = left;
	vertexBuffer[13] = bottom;
	vertexBuffer[14] = 0.0f;
	vertexBuffer[15] = 1.0f;
	
}

void Sprite::PutGLColorInfo(float* colorBuffer)
{
	float red = this->color.red;
	float blue = this->color.blue;
	float green = this->color.green;
	float alpha = this->color.alpha;
	// Top/Left
	colorBuffer[0] = red;
	colorBuffer[1] = green;
	colorBuffer[2] = blue;
	colorBuffer[3] = alpha;
	// Top/Right
	colorBuffer[4] = red;
	colorBuffer[5] = green;
	colorBuffer[6] = blue;
	colorBuffer[7] = alpha;
	// Bottom/Right
	colorBuffer[8] = red;
	colorBuffer[9] = green;
	colorBuffer[10] = blue;
	colorBuffer[11] = alpha;
	// Bottom/Left
	colorBuffer[12] = red;
	colorBuffer[13] = green;
	colorBuffer[14] = blue;
	colorBuffer[15] = alpha;
}

void Sprite::PutGLIndexInfo(unsigned short* indexBuffer, unsigned short dataStartIndex)
{
	// TopRight Triangle
	//  Top/Left
	indexBuffer[0] = dataStartIndex;
	//  Top/Right
	indexBuffer[1] = dataStartIndex + 1;
	//  Bottom/Right
	indexBuffer[2] = dataStartIndex + 2;
	// BottomLeft Triangle
	//  Bottom/Right
	indexBuffer[3] = dataStartIndex + 2;
	//  Bottom/Left
	indexBuffer[4] = dataStartIndex + 3;
	//  Top/Left
	indexBuffer[5] = dataStartIndex;
}