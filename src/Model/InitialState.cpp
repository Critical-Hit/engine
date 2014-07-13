#include "InitialState.h"

InitialState::InitialState()
{
    
}

void InitialState::Initialize(GameStateManager* manager)
{
    GameState::Initialize(manager);

    this->sign = -1;
    this->increment = 0.016667f;
}

void InitialState::Update()
{
	float clearColor = this->graphicsManager->GetClearColor();
    // For now just alternate between a 0 and 1 color value to flash a color.
    if(clearColor <= 0.0f || clearColor >= 1.0f)
    {
        sign *= -1;
    }
	this->graphicsManager->SetClearColor((this->sign * this->increment) + clearColor);
}

void InitialState::Pause()
{
    GameState::Pause();
}

void InitialState::Resume()
{
    GameState::Resume();
}

void InitialState::Destroy()
{
	GameState::Destroy();
}