#ifndef Core_ControllerPackage_h
#define Core_ControllerPackage_h

#include "GraphicsManager.h"
#include "InputManager.h"
#include "SoundManager.h"

class ControllerPackage
{
public:
    /**
     * Default constructor that creates a new instance of a ControllerPackage.
     */
    ControllerPackage(const GraphicsManager* graphicsManager, const InputManager* inputManager, const SoundManager* soundManager);
    
    /**
     * Returns a pointer to the game's GraphicsManager.
     */
    const GraphicsManager* GetGraphicsManager();
    
    /**
     * Returns a pointer to the game's InputManager.
     */
    const InputManager* GetInputManager();
    
    /**
     * Returns a pointer to the game's SoundManager.
     */
    const SoundManager* GetSoundManager();
    
private:
    // Private constructors to disallow access.
    ControllerPackage(ControllerPackage const &other);
    ControllerPackage operator=(ControllerPackage other);

	// The managers to be provided to the game manager
	const GraphicsManager* graphicsManager;
	const InputManager* inputManager;
	const SoundManager* soundManager;
};

#endif
