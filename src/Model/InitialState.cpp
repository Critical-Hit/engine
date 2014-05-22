#include "InitialState.h"

InitialState::InitialState()
{
    
}

void InitialState::Initialize(GameStateManager* manager)
{
    this->sign = -1;
    this->increment = 0.016667f;
    this->colorValue = 0.0f;
    
    GameState::Initialize(manager);
}

float InitialState::Update()
{
    // For now just alternate between a 0 and 1 color value to flash a color.
    if(this->colorValue <= 0.0f || this->colorValue >= 1.0f)
    {
        sign *= -1;
    }
    this->colorValue += (this->sign * this->increment);
    return this->colorValue;
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
    
}