#include "InitialState.h"
#include "Color.h"
#include "Sprite.h"

InitialState::InitialState()
{

}

void InitialState::Initialize(std::shared_ptr<GameStateManager> manager)
{
    GameState::Initialize(manager);

    // Magic demo stuff
    this->sign = -1;
    this->increment = 0.016667f;
    this->graphicsManager->RegisterSprite(std::make_shared<Sprite>(-0.5, 0.5f, 0.5f, 0.5f, Color(1.0f, 0.0f, 0.0f, 1.0f)));
    this->graphicsManager->RegisterSprite(std::make_shared<Sprite>( 0.0, 0.5f, 0.5f, 0.5f, Color(0.0f, 1.0f, 0.0f, 1.0f)));
    this->graphicsManager->RegisterSprite(std::make_shared<Sprite>(-0.5, 0.0f, 0.5f, 0.5f, Color(0.0f, 0.0f, 1.0f, 1.0f)));
    this->graphicsManager->RegisterSprite(std::make_shared<Sprite>(0.0, 0.0f, 0.5f, 0.5f, Color(1.0f, 1.0f, 0.0f, 1.0f)));

    this->graphicsManager->RegisterSprite(std::make_shared<Sprite>(-1.0, 1.0f, 0.5f, 0.5f, Color(1.0f, 0.0f, 0.0f, 1.0f)));
    this->graphicsManager->RegisterSprite(std::make_shared<Sprite>(0.5, 1.0f, 0.5f, 0.5f, Color(0.0f, 1.0f, 0.0f, 1.0f)));
    this->graphicsManager->RegisterSprite(std::make_shared<Sprite>(-1.0, -0.5f, 0.5f, 0.5f, Color(0.0f, 0.0f, 1.0f, 1.0f)));
    this->graphicsManager->RegisterSprite(std::make_shared<Sprite>(0.5, -0.5f, 0.5f, 0.5f, Color(1.0f, 1.0f, 0.0f, 1.0f)));
}

void InitialState::Update()
{
    // More magic demo stuff
    float clearColorValue = (graphicsManager->GetClearColor()).blue;
    // For now just alternate between a 0 and 1 color value to flash a color.
    if(clearColorValue <= 0.0f || clearColorValue >= 1.0f)
    {
        sign *= -1;
    }
    clearColorValue = (this->sign * this->increment) + clearColorValue;
    Color newClearColor(0.0f, clearColorValue, clearColorValue, 1.0f);
    this->graphicsManager->SetClearColor(newClearColor);
    this->graphicsManager->GetCamera()->MoveBy(increment * sign, 0.0f);
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
