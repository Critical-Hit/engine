#ifndef Core_InputView_h
#define Core_InputView_h

#include "ControllerPackage.h"

/**
 * Provides a full set of logic for accessing input.
 * 
 * Currently does nothing, though.
 */
class InputView
{
public:
    /**
     * Default constructor that creates a new instance of an InputView.
     */
    InputView(ControllerPackage* controllerPackage);
    
    /**
     * Initializes the InputView.
     */
    void Initialize();
    
    /**
     * Updates the InputView.
     */
    void Update();
    
private:
    // Private constructors to disallow access.
    InputView(InputView const &other);
    InputView operator=(InputView other);

	/**
	 * InputManager with information about input
	 */
	InputManager* const inputManager;
};

#endif
