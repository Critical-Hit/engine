#include "GameState.h"
#include "IGraphicsManager.h"

void GameState::Initialize(std::shared_ptr<GameStateManager> manager)
{
    this->manager = manager;
    this->controllerPackage = std::make_shared<ControllerPackage>(Model::CreateIGraphicsManager(), std::make_shared<InputManager>(), SoundManager::GetInstance());
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
