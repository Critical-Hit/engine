#include <stdexcept>
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
	int registeredCountBeforeAdd = this->registeredSprites.size();
	this->registeredSprites.insert(sprite);
	if ((registeredCountBeforeAdd + 1) != this->registeredSprites.size())
	{
		throw new std::invalid_argument("A sprite was registered that was already registered.");
	}
}

void GraphicsManager::UnRegisterSprite(Sprite* sprite)
{
	int registeredCountBeforeAdd = this->registeredSprites.size();
	this->registeredSprites.erase(sprite);
	if ((registeredCountBeforeAdd - 1) != this->registeredSprites.size())
	{
		throw new std::invalid_argument("A sprite was unregistered that wasn't registered.");
	}
}

int GraphicsManager::GetSpriteCount()
{
	return this->registeredSprites.size();
}

void GraphicsManager::AddSpritesToVCIBuffer(float* vertexBuffer, float* colorBuffer, unsigned short* indexBuffer, unsigned short dataStartIndex)
{
	int spriteNumber = 0;
	for each (Sprite* sprite in this->registeredSprites)
	{
		sprite->PutGLVertexInfo(&(vertexBuffer[16 * spriteNumber])); // 16 = 4 vertices * 4 coordinates
		sprite->PutGLColorInfo(&(colorBuffer[16 * spriteNumber])); // 16 = 4 vertices * 4 channels
		sprite->PutGLIndexInfo(indexBuffer, dataStartIndex + 6 * spriteNumber); // 6 = 2 triangles * 3 coordinates
		spriteNumber++;
	}
}