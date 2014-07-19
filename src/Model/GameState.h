#ifndef Core_GameState_h
#define Core_GameState_h

#include "GameStateManager.h"
class GameStateManager;

/**
 * Contains logic for managing underlying functions used by the GameStateManager
 * for management of states.  When these virtual methods are overriden, the base
 * should ALWAYS be called at the beginning of the method.
 *
 */
class GameState
{
public:
    /**
     * Initializes the GameState with the given GameStateManager.
     */
    virtual void Initialize(GameStateManager* manager);
    
    /**
     * Updates this State.
     */
	virtual void Update() = 0;
    
    /**
     * Pauses this State to be resumed later, saves the ControllerPackage.
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
    
protected:
    /**
     * The GameStateManager managing this State.
     */
    GameStateManager* manager;

	/**
	 * Pointers to the managers of the controller package
	 */
	GraphicsManager* graphicsManager;
	InputManager* inputManager;
	SoundManager* soundManager;
    ResourceManager* resourceManager;

private:
	/**
	 * ControllerPackages that the managers belong to
	 */
	ControllerPackage* controllerPackage;
    
};

#endif
