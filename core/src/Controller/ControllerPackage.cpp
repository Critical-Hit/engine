#include "ControllerPackage.h"

std::weak_ptr<ControllerPackage> ControllerPackage::activeControllerPackage;

ControllerPackage::ControllerPackage(std::shared_ptr<GraphicsManager> graphicsManager, std::shared_ptr<Model::IInputManager> inputManager, std::shared_ptr<SoundManager> soundManager)
: graphicsManager(graphicsManager),
inputManager(inputManager),
soundManager(soundManager)
{

}

ControllerPackage::~ControllerPackage()
{

}

std::shared_ptr<GraphicsManager> ControllerPackage::GetGraphicsManager()
{
    return this->graphicsManager;
}

std::shared_ptr<Model::IInputManager> ControllerPackage::GetInputManager()
{
    return this->inputManager;
}

std::shared_ptr<SoundManager> ControllerPackage::GetSoundManager()
{
    return this->soundManager;
}

std::shared_ptr<ResourceManager> ControllerPackage::GetResourceManager()
{
    return this->resourceManager;
}

void ControllerPackage::Activate()
{
    ControllerPackage::activeControllerPackage = this->shared_from_this();
}

std::weak_ptr<ControllerPackage> ControllerPackage::GetActiveControllerPackage()
{
    return ControllerPackage::activeControllerPackage;
}
