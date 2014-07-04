#include "ControllerPackage.h"

ControllerPackage::ControllerPackage(GraphicsManager* const graphicsManager, InputManager* const inputManager, SoundManager* const soundManager)
: graphicsManager(graphicsManager),
inputManager(inputManager),
soundManager(soundManager)
{
	
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
