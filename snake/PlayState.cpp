#include "PlayState.h"
#include "GraphicsInterface.h"
#include "InputInterface.h"

//TODO: Make SnakePiece class, each has a Sprite with the interface:
// Sprite snakeHead = new Sprite(x, y, width, height, color);
// snakeHead.MoveBy(x, y);
// The Snake class will have a list of SnakePieces

// TODO: Also don't forget to add dependencies on Core

PlayState::PlayState()
{
    this->snake = new Snake();
    this->lastFacing.Set(1, 0);
    this->inUp = false;
    this->inDown = false;
    this->inLeft = false;
    this->inRight = false;
    this->updatesSinceTick = 0;
}

PlayState::~PlayState()
{

}

void PlayState::Initialize(GameStateManager* manager)
{
    GameState::Initialize(manager);

    // Graphics Initialization
    GraphicsInterface graphics;
    graphics.Initialize(this->graphicsManager);
    graphics.SetBackgroundColor(1.0f);

    // Input Initialization
    InputInterface input;
    input.Initialize(this->inputManager);
    input.OnEscapePressed = [this]() { /* Exit application*/ };
    input.OnWPressed = [this]() { this->inUp = true; };
    input.OnAPressed = [this]() { this->inLeft = true; };
    input.OnSPressed = [this]() { this->inDown = true; };
    input.OnDPressed = [this]() { this->inRight = true; };
    input.OnWReleased = [this]() { this->inUp = false; };
    input.OnAReleased = [this]() { this->inLeft = false; };
    input.OnSReleased = [this]() { this->inDown = false; };
    input.OnDReleased = [this]() { this->inRight = false; };
}

void PlayState::Update()
{
    // Only tick after a specified number of updates.
    if (updatesSinceTick++ >= PlayState::updatesPerTick)
    {
        updatesSinceTick = 0;
        move();
        if (checkDeath())
        {
            die();
            return;
        }
        if (checkCircle())
        {
            extend();
        }
    }
    printf("Position is: (%d, %d)\n", this->snake->Position.X, this->snake->Position.Y);
}

//TODO: Move this into the Snake class
void PlayState::move()
{
    //TODO: Cache movement for extending
    if (inUp)
    {
        this->snake->Position.Y += 1;
        this->lastFacing.Set(0, 1);
    }
    else if (inLeft)
    {
        this->snake->Position.X -= 1;
        this->lastFacing.Set(-1, 0);
    }
    else if (inDown)
    {
        this->snake->Position.Y -= 1;
        this->lastFacing.Set(0, -1);
    }
    else if (inRight)
    {
        this->snake->Position.X += 1;
        this->lastFacing.Set(1, 0);
    }
    else
    {
        this->snake->Position.X += this->lastFacing.X;
        this->snake->Position.Y += this->lastFacing.Y;
    }

    // Stay within the grid bounds
    if (this->snake->Position.X > (PlayState::gridSize - 1))
    {
        this->snake->Position.X -= PlayState::gridSize;
    }
    if (this->snake->Position.Y > (PlayState::gridSize - 1))
    {
        this->snake->Position.Y -= PlayState::gridSize;
    }
}

bool PlayState::checkDeath()
{
    return false;
}

void PlayState::die()
{

}

bool PlayState::checkCircle()
{
    return false;
}

void PlayState::extend()
{

}
