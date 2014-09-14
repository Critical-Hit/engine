#ifndef Core_GameState_h
#define Core_GameState_h

#include "GameStateManager.h"
class GameStateManager;

/**
 * Base class of all GameStates. Game logic goes inside your subclasses of GameState. 
 * Initialize is where you set up all logic at the start of the state, Update is where 
 * you define your game logic that updates every iteration of the game loop. The other 
 * methods are to interact well with the GameStateManager.
 *
 * GameState contains logic for managing underlying functions used by the GameStateManager
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
