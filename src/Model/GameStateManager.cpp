#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
    
}

void GameStateManager::Initialize(GameState* state)
{
    state->Initialize(this);
    gameStates.push(state);
}

float GameStateManager::Update()
{
    return gameStates.top()->Update();
}

void GameStateManager::PushState(GameState* state)
{
    if(!gameStates.empty())
    {
        gameStates.top()->Pause();
    }
    gameStates.push(state);
    gameStates.top()->Initialize(this);
}

GameState* GameStateManager::PopState()
{
    GameState* top = gameStates.top();
    top->Pause();
    top->Destroy();
    gameStates.pop();
    return top;
}

void GameStateManager::SwapState(GameState* state)
{
    this->PopState();
    this->PushState(state);
}