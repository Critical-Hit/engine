#ifndef Core_GameStateManager_h
#define Core_GameStateManager_h

#include <stack>

#include "ControllerPackage.h"
#include "GameState.h"
class GameState;

/**
 * Manages a stack of GameStates, allowing smooth transitioning between states,
 * including saving old states that remain "underneath" the current state. Allows
 * pushing a state on top of the current, so that it can be resumed when the pushed
 * state is popped, or swapping states if there is no need to return to a state later.
 */
class GameStateManager
{
public:
	/**
	 * Constructor that creates a new GameStateManager with a pointer to a ControllerPackage
	 */
	GameStateManager();

    /**
     * Adds and initializes the given state to the GameStateManager.
     */
    void Initialize(GameState* state);
    
    /**
     * Updates the current state.
     */
    void Update();
    
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
