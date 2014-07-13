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
    InputView();
    
    /**
     * Initializes the InputView.
     */
    void Initialize();
    
    /**
     * Updates the InputView.
     */
    void Update(InputManager* inputManager);
    
private:
    // Private constructors to disallow access.
    InputView(InputView const &other);
    InputView operator=(InputView other);
};

#endif
