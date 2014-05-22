#include "ControllerPackage.h"

ControllerPackage::ControllerPackage(const GraphicsManager* graphicsManager, const InputManager* inputManager, const SoundManager* soundManager)
{
	this->graphicsManager = graphicsManager;
	this->inputManager = inputManager;
	this->soundManager = soundManager;
}

const GraphicsManager* ControllerPackage::GetGraphicsManager()
{
	return this->graphicsManager;
}


const InputManager* ControllerPackage::GetInputManager()
{
	return this->inputManager;
}

const SoundManager* ControllerPackage::GetSoundManager()
{
	return this->soundManager;
}
