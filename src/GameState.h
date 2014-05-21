#ifndef Core_GameState_h
#define Core_GameState_h

#include "GameStateManager.h"
class GameStateManager;

class GameState
{
public:
    /**
     * Default constructor that creates a new instance of a GameState.
     */
    GameState() { }
    
    /**
     * Initializes the GameState with the given GameStateManager.
     */
    virtual void Initialize(GameStateManager* manager)
    {
        this->manager = manager;
    }
    
    /**
     * Updates this State.
     */
    virtual float Update() { return 0; }
    
    /**
     * Pauses this State to be resumed later.
     */
    virtual void Pause() { }
    
    /**
     * Resumes this State after being paused.
     */
    virtual void Resume() { }
    
    /**
     * Destroys this State because it won't be used again.
     */
    virtual void Destroy() { }
    
private:
    GameState(GameState const &other);
    GameState operator=(GameState other);
    
    /**
     * The GameStateManager managing this State.
     */
    GameStateManager* manager;
    
};

#endif
