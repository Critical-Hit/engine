#ifndef Core_InitialState_h
#define Core_InitialState_h

#include "GameState.h"

class InitialState : public GameState
{
public:
    /**
     * Default constructor that creates a new instance of a Controller.
     */
    InitialState();
    
    /**
     * Initializes the GraphicsView.
     */
    virtual void Initialize(GameStateManager* manager);
    
    /**
     * Updates this State.
     */
    virtual float Update();
    
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
     * Test variables for the initial state.
     */
    int sign;
    float increment;
    float colorValue;
};

#endif
