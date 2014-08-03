#include "GameState.h"

void GameState::Initialize(GameStateManager* manager)
{
    this->manager = manager;
    //ResourceManager::Initialize();
    this->controllerPackage = new ControllerPackage(new GraphicsManager(), new InputManager(), new SoundManager());
    this->graphicsManager = this->controllerPackage->GetGraphicsManager();
    this->inputManager = this->controllerPackage->GetInputManager();
    this->soundManager = this->controllerPackage->GetSoundManager();
    this->resourceManager = this->controllerPackage->GetResourceManager();
    this->controllerPackage->Activate();
}

void GameState::Pause()
{

}

void GameState::Resume()
{
    this->controllerPackage->Activate();
}

void GameState::Destroy() 
{ 

}