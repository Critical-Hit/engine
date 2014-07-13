#ifndef Core_InputManager_h
#define Core_InputManager_h

class InputManager
{
public:
    /**
     * Default constructor that creates a new instance of an InputManager.
     */
    InputManager();
    
	/**
	* Sets all variables of this instance to match the other instance.
	*/
	void CopyFrom(InputManager* other);

private:
    // Private constructors to disallow access.
    InputManager(InputManager const &other);
    InputManager operator=(InputManager other);
};

#endif
