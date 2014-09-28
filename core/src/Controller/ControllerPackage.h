#ifndef Core_ControllerPackage_h
#define Core_ControllerPackage_h

#include <memory>
#include "InputManager.h"
#include "SoundManager.h"
#include "ResourceManager.h"
#include "IGraphicsManager.h"

class InputManager;
class SoundManager;

/**
 * This class is used to gather together access to the various managers
 * used to control the engine's view, and is used by the model to effect
 * graphics, get input, and play sounds.
 */
class ControllerPackage : public enable_shared_from_this<ControllerPackage>
{
public:
    /**
     * Constructor that creates a new instance of a ControllerPackage given managers.
     */
    ControllerPackage(std::shared_ptr<Model::IGraphicsManager> graphicsManager, std::shared_ptr<InputManager> inputManager, std::shared_ptr<SoundManager> soundManager);
    
    /**
     * Destructor
     */
    ~ControllerPackage();
    /**
     * Returns a pointer to the game's GraphicsManager.
     */
    std::shared_ptr<Model::IGraphicsManager> GetGraphicsManager();
    
    /**
     * Returns a pointer to the game's InputManager.
     */
    std::shared_ptr<InputManager> GetInputManager();

    /**
     * Returns a pointer to the game's SoundManager.
     */
    std::shared_ptr<SoundManager> GetSoundManager();
    
    /**
     * Returns a pointer to the game's ResourceManager.
     */
    std::shared_ptr<ResourceManager> GetResourceManager();

    /**
     * Activates this ControllerPackage so it will be used by
     * by the engine's view.
     */
    void Activate();

    /**
     * Gets the active ControllerPackage
     */
    static std::weak_ptr<ControllerPackage> GetActiveControllerPackage();
    
private:
    // Private constructors to disallow access.
    ControllerPackage(ControllerPackage const &other);
    ControllerPackage operator=(ControllerPackage other);

    // The managers to be provided to the game manager
    std::shared_ptr<Model::IGraphicsManager> graphicsManager;
    std::shared_ptr<InputManager> inputManager;
    std::shared_ptr<SoundManager> soundManager;
    std::shared_ptr<ResourceManager> resourceManager;

    static std::weak_ptr<ControllerPackage> activeControllerPackage;
};

#endif
