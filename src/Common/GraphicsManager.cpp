#include "GraphicsManager.h"

GraphicsManager::GraphicsManager()
{
	this->clearColor = 0.0f;
}

float GraphicsManager::GetClearColor()
{
	return this->clearColor;
}

void GraphicsManager::SetClearColor(float clearColor)
{
	this->clearColor = clearColor;
}