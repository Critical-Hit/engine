#include "StartState.h"
#include "PlayState.h"
#include "InputInterface.h"
#include "GraphicsInterface.h"

StartState::StartState()
{

}

void StartState::Initialize(GameStateManager* manager)
{
    GameState::Initialize(manager);

    // Graphics Initialization
    GraphicsInterface graphics;
    graphics.Initialize(this->graphicsManager);
    graphics.SetBackgroundColor(0.3f);

    // Input Initialization
    InputInterface input;
    input.OnEnterPressed = [this]() { 
        this->manager->SwapState(new PlayState());
    };
    input.Initialize(this->inputManager);
}

void StartState::Update()
{
    this->manager->SwapState(new PlayState());
}