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
    ControllerPackage();
    
    /**
     * The games GraphicsManager.
     */
    GraphicsManager GraphicsManager;
    
    /**
     * The games InputManager.
     */
    InputManager InputManager;
    
    /**
     * The games SoundManager.
     */
    SoundManager SoundManager;
    
private:
    // Private constructors to disallow access.
    ControllerPackage(ControllerPackage const &other);
    ControllerPackage operator=(ControllerPackage other);
};

#endif
