#include <stdexcept>
#include <thread>
#include <chrono>
#include "GraphicsManager.h"
#include "Color.h"
#include "Sprite.h"

GraphicsManager::GraphicsManager() : clearColor(0.0f, 0.0f, 0.0f, 1.0f)
{

}

GraphicsManager::~GraphicsManager()
{

}

Color GraphicsManager::GetClearColor()
{
	return this->clearColor;
}

void GraphicsManager::SetClearColor(Color clearColor)
{
	this->clearColor = clearColor;
}

void GraphicsManager::RegisterSprite(Sprite* sprite)
{
	this->registeredSpritesMutex.lock();
	int registeredCountBeforeAdd = (int)this->registeredSprites.size();
	this->registeredSprites.insert(sprite);
	if ((registeredCountBeforeAdd + 1) != (int)this->registeredSprites.size())
	{
		throw new std::invalid_argument("A sprite was registered that was already registered.");
	}
	this->registeredSpritesMutex.unlock();
}

void GraphicsManager::UnRegisterSprite(Sprite* sprite)
{
	this->registeredSpritesMutex.lock();
	int registeredCountBeforeAdd = (int)this->registeredSprites.size();
	this->registeredSprites.erase(sprite);
	if ((registeredCountBeforeAdd - 1) != (int)this->registeredSprites.size())
	{
		throw new std::invalid_argument("A sprite was unregistered that wasn't registered.");
	}
	this->registeredSpritesMutex.unlock();
}

int GraphicsManager::GetSpriteCount()
{
	return (int)this->registeredSprites.size();
}

void GraphicsManager::PrepareToAddSprites()
{
	this->registeredSpritesMutex.lock();
	this->spriteIterator = this->registeredSprites.begin();
}

bool GraphicsManager::AddSpriteToVCIBuffer(float* vertexBuffer, float* colorBuffer, unsigned short* indexBuffer, unsigned short dataStartIndex)
{
	if (this->spriteIterator == this->registeredSprites.end())
	{
		this->registeredSpritesMutex.unlock();
		return false;
	}
	Sprite* sprite = *(this->spriteIterator);
	sprite->PutGLVertexInfo(vertexBuffer); // 16 = 4 vertices * 4 coordinates
	sprite->PutGLColorInfo(colorBuffer); // 16 = 4 vertices * 4 channels
	sprite->PutGLIndexInfo(indexBuffer, dataStartIndex); // 6 = 2 triangles * 3 coordinates
	this->spriteIterator++;
	return true;
}
