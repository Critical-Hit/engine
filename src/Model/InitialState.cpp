#include "InitialState.h"
#include "Color.h"

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
	float clearColorValue = (graphicsManager->GetClearColor()).blue;
    // For now just alternate between a 0 and 1 color value to flash a color.
    if(clearColorValue <= 0.0f || clearColorValue >= 1.0f)
    {
        sign *= -1;
    }
	clearColorValue = (this->sign * this->increment) + clearColorValue;
	this->graphicsManager->SetClearColor(Color(0.0f, clearColorValue, clearColorValue, 1.0f));
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