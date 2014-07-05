#include "GameStateManager.h"

GameStateManager::GameStateManager(ControllerPackage* controllerPackage)
{
	this->controllerPackage = controllerPackage;
}

void GameStateManager::Initialize(GameState* state)
{
    state->Initialize(this, this->controllerPackage);
    gameStates.push(state);
}

void GameStateManager::Update()
{
    gameStates.top()->Update();
}

void GameStateManager::PushState(GameState* state)
{
    if(!gameStates.empty())
    {
        gameStates.top()->Pause();
    }
    gameStates.push(state);
    gameStates.top()->Initialize(this, this->controllerPackage);
}

GameState* GameStateManager::PopState()
{
    GameState* top = gameStates.top();
    top->Pause();
    top->Destroy();
    gameStates.pop();
	gameStates.top()->Resume();
    return top;
}

void GameStateManager::SwapState(GameState* state)
{
    this->PopState();
    this->PushState(state);
}