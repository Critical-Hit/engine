#include "GameState.h"
#include "Snake.h"

class PlayState : public GameState
{
public:
    PlayState();
    ~PlayState();
    void Initialize(GameStateManager* manager);
    void Update();

private:
    void move();
    bool checkDeath();
    bool checkCircle();
    void die();
    void extend();

    Snake* snake;

    bool inUp;
    bool inDown;
    bool inLeft;
    bool inRight;

    Vec2 lastFacing;

    static const int updatesPerTick = 60;
    static const int gridSize = 10; // gridSize wide and gridSize tall

    int updatesSinceTick;
};