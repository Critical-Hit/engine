#ifndef Game_InitialState_h
#define Game_InitialState_h

#include "GameState.h"
#include <memory>

/**
 * The entry point used the GameState system. It should be modified to house
 * the entry point for a user's game logic.
 */
class InitialState : public GameState
{
public:
    /**
     * Default constructor that creates a new instance of an InitialState.
     */
    InitialState();
    
    /**
     * Initializes the State.
     */
    virtual void Initialize(std::shared_ptr<GameStateManager> manager);
    
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
     * Variables for the default demo.
     */
    int sign;
    float increment;
    float currentColor;
};

#endif
