#include "GameState.h"

class StartState : public GameState
{
public:
    StartState();
    void Initialize(GameStateManager* manager);
    void Update();
};