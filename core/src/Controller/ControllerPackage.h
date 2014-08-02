#ifndef Core_ControllerPackage_h
#define Core_ControllerPackage_h

#include "GraphicsManager.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "ResourceManager.h"

class InputManager;
class SoundManager;
/**
 * This class is used to gather together access to the various managers
 * used to control the engine's view, and is used by the model to effect
 * graphics, get input, and play sounds.
 */
class ControllerPackage
{
public:
    /**
     * Constructor that creates a new instance of a ControllerPackage given managers.
     */
    ControllerPackage(GraphicsManager* const graphicsManager, InputManager* const inputManager, SoundManager* const soundManager, ResourceManager* const resourceManager);
    
	/**
	 * Destructor
	 */
	~ControllerPackage();

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
    
    /**
     * Returns a pointer to the game's ResourceManager.
     */
    ResourceManager* const GetResourceManager();

	/**
	 * Returns a clone of this ControllerPackage
	 */
	void CopyFrom(ControllerPackage* copy);

    /**
     * Activates this ControllerPackage so it will be used by
     * by the engine's view.
     */
    void Activate();

    /**
     * Gets the active ControllerPackage
     */
    static ControllerPackage* GetActiveControllerPackage();
    
private:
    // Private constructors to disallow access.
    ControllerPackage(ControllerPackage const &other);
    ControllerPackage operator=(ControllerPackage other);

	// The managers to be provided to the game manager
	GraphicsManager* graphicsManager;
	InputManager* inputManager;
    SoundManager* soundManager;
    ResourceManager* resourceManager;

    static ControllerPackage* activeControllerPackage;
};

#endif
