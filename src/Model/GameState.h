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
    virtual void Initialize(GameStateManager* manager, ControllerPackage* controllerPackage)
    {
		this->cachedControllerPackage = new ControllerPackage(new GraphicsManager(), new InputManager(), new SoundManager());
        this->manager = manager;
		this->controllerPackage = controllerPackage;
		this->graphicsManager = this->controllerPackage->GetGraphicsManager();
		this->inputManager = this->controllerPackage->GetInputManager();
		this->soundManager = this->controllerPackage->GetSoundManager();
    }
    
    /**
     * Updates this State.
     */
	virtual void Update() = 0;
    
    /**
     * Pauses this State to be resumed later, saves the ControllerPackage.
     */
    virtual void Pause() 
	{
		this->cachedControllerPackage->CopyFrom(this->controllerPackage);
		this->graphicsManager = this->cachedControllerPackage->GetGraphicsManager();
		this->inputManager = this->cachedControllerPackage->GetInputManager();
		this->soundManager = this->cachedControllerPackage->GetSoundManager();
	}
    
    /**
     * Resumes this State after being paused.
     */
    virtual void Resume() 
	{
		this->controllerPackage->CopyFrom(this->cachedControllerPackage);
		this->graphicsManager = this->controllerPackage->GetGraphicsManager();
		this->inputManager = this->controllerPackage->GetInputManager();
		this->soundManager = this->controllerPackage->GetSoundManager();
	}
    
    /**
     * Destroys this State because it won't be used again.
     */
    virtual void Destroy() { }
    
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

private:
	/**
	 * ControllerPackages that the managers belong to
	 */
	ControllerPackage* controllerPackage;
	ControllerPackage* cachedControllerPackage;
    
};

#endif
