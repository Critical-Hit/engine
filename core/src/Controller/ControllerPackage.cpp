#include "ControllerPackage.h"

ControllerPackage* ControllerPackage::activeControllerPackage = nullptr;

ControllerPackage::ControllerPackage(GraphicsManager* const graphicsManager, InputManager* const inputManager, SoundManager* const soundManager, ResourceManager* const resourceManager)
: graphicsManager(graphicsManager),
inputManager(inputManager),
soundManager(soundManager),
resourceManager(resourceManager)
{
	
}

ControllerPackage::~ControllerPackage()
{
	delete this->graphicsManager;
	delete this->inputManager;
	delete this->soundManager;
}

GraphicsManager* const ControllerPackage::GetGraphicsManager()
{
	return this->graphicsManager;
}


InputManager* const ControllerPackage::GetInputManager()
{
	return this->inputManager;
}

SoundManager* const ControllerPackage::GetSoundManager()
{
	return this->soundManager;
}

ResourceManager* const ControllerPackage::GetResourceManager()
{
    return this->resourceManager;
}

void ControllerPackage::Activate()
{
    ControllerPackage::activeControllerPackage = this;
}

ControllerPackage* ControllerPackage::GetActiveControllerPackage()
{
    return ControllerPackage::activeControllerPackage;
}
