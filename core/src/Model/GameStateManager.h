#ifndef Core_GameStateManager_h
#define Core_GameStateManager_h

#include <stack>
#include <memory>

#include "ControllerPackage.h"
#include "GameState.h"
class GameState;

/**
 * Manages a stack of GameStates, allowing smooth transitioning between states,
 * including saving old states that remain "underneath" the current state. 
 */
class GameStateManager : public std::enable_shared_from_this<GameStateManager>
{
public:
    /**
     * Constructor that creates a new GameStateManager with a pointer to a ControllerPackage
     */
    GameStateManager();

    /**
     * Adds and initializes the given state to the GameStateManager.
     */
    void Initialize(std::shared_ptr<GameState> state);
    /**
     * Updates the current state.
     */
    void Update();

    /**
     * Pauses the current state and starts the given state.
     */
    void PushState(std::shared_ptr<GameState> state);
    
    /**
     * Removes the current state and resumes the previous state.
     */
    std::shared_ptr<GameState> PopState();
    
    /**
     * Removes the current state and starts the given state.
     */
    void SwapState(std::shared_ptr<GameState> state);
    
private:
    // Private constructors to disallow access.
    GameStateManager(GameStateManager const &other);
    GameStateManager operator=(GameStateManager other);

    /**
     * Contains the current stack of game states.
     */
    std::stack<std::shared_ptr<GameState>> gameStates;
};

#endif
