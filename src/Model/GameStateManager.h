#ifndef Core_GameStateManager_h
#define Core_GameStateManager_h

#include <stack>

#include "GameState.h"
class GameState;

class GameStateManager
{
public:
    /**
     * Default constructor that creates a new instance of a GameStateManager.
     */
    GameStateManager();
    
    /**
     * Adds and initializes the given state to the GameStatemanager.
     */
    void Initialize(GameState* state);
    
    /**
     * Updates the current state.
     */
    float Update();
    
    /**
     * Pauses the current state and starts the given state.
     */
    void PushState(GameState* state);
    
    /**
     * Removes the current state and resumes the previous state.
     */
    GameState* PopState();
    
    /**
     * Removes the current state and starts the given state.
     */
    void SwapState(GameState* state);
    
private:
    // Private constructors to disallow access.
    GameStateManager(GameStateManager const &other);
    GameStateManager operator=(GameStateManager other);
    
    /**
     * Contains the current stack of game states.
     */
    std::stack<GameState*> gameStates;
};

#endif
