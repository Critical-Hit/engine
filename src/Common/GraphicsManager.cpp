#include "GraphicsManager.h"

GraphicsManager::GraphicsManager()
{
	this->clearColor = 0.0f;
}

GraphicsManager::~GraphicsManager()
{

}

float GraphicsManager::GetClearColor()
{
	return this->clearColor;
}

void GraphicsManager::SetClearColor(float clearColor)
{
	this->clearColor = clearColor;
}

void GraphicsManager::CopyFrom(GraphicsManager* other)
{
	// Set all variables to the same as the other
	this->clearColor = other->clearColor;
}