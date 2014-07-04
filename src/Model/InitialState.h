#ifndef Core_InitialState_h
#define Core_InitialState_h

#include "GameState.h"

/**
 * The entry point used the GameState system. It should be modified to house
 * the entry point for a user's game logic.
 */
class InitialState : public GameState
{
public:
    /**
     * Default constructor that creates a new instance of a Controller.
     */
    InitialState();
    
    /**
     * Initializes the State.
     */
    virtual void Initialize(GameStateManager* manager, ControllerPackage* controllerPackage);
    
    /**
     * Updates this State.
     */
    virtual void Update();
    
    /**
     * Pauses this State to be resumed later.
     */
    virtual void Pause();
    
    /**
     * Resumes this State after being paused.
     */
    virtual void Resume();
    
    /**
     * Destroys this State because it won't be used again.
     */
    virtual void Destroy();
    
private:
    // Private constructors to disallow access.
    InitialState(InitialState const &other);
    InitialState operator=(InitialState other);
    
	/**
	 * The GraphicsManager to update
	 */
	GraphicsManager* graphicsManager;

    /**
     * Test variables for the initial state.
     */
    int sign;
    float increment;
};

#endif
