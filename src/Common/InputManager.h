#ifndef Core_InputManager_h
#define Core_InputManager_h

class InputManager
{
public:
    /**
     * Default constructor that creates a new instance of an InputManager.
     */
    InputManager();

private:
    // Private constructors to disallow access.
    InputManager(InputManager const &other);
    InputManager operator=(InputManager other);
};

#endif
