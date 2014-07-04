#ifndef Core_ControllerPackage_h
#define Core_ControllerPackage_h

#include "GraphicsManager.h"
#include "InputManager.h"
#include "SoundManager.h"

/**
 * This class is used to gather together access to the various managers
 * used to control the engine's view, and is used by the model to effect
 * graphics, get input, and play sounds.
 */
class ControllerPackage
{
public:
    /**
     * Default constructor that creates a new instance of a ControllerPackage.
     */
    ControllerPackage(GraphicsManager* const graphicsManager, InputManager* const inputManager, SoundManager* const soundManager);
    
    /**
     * Returns a pointer to the game's GraphicsManager.
     */
    GraphicsManager* const GetGraphicsManager();
    
    /**
     * Returns a pointer to the game's InputManager.
     */
    InputManager* const GetInputManager();
    
    /**
     * Returns a pointer to the game's SoundManager.
     */
    SoundManager* const GetSoundManager();
    
private:
    // Private constructors to disallow access.
    ControllerPackage(ControllerPackage const &other);
    ControllerPackage operator=(ControllerPackage other);

	// The managers to be provided to the game manager
	GraphicsManager* const graphicsManager;
	InputManager* const inputManager;
	SoundManager* const soundManager;
};

#endif
