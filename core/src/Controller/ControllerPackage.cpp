#include "ControllerPackage.h"

ControllerPackage* ControllerPackage::activeControllerPackage = nullptr;

ControllerPackage::ControllerPackage(GraphicsManager* const graphicsManager, InputManager* const inputManager, ResourceManager* const resourceManager)
: graphicsManager(graphicsManager),
inputManager(inputManager),
resourceManager(resourceManager)
{
	
}

ControllerPackage::~ControllerPackage()
{
	delete this->graphicsManager;
	delete this->inputManager;
}

GraphicsManager* const ControllerPackage::GetGraphicsManager()
{
	return this->graphicsManager;
}


InputManager* const ControllerPackage::GetInputManager()
{
	return this->inputManager;
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
