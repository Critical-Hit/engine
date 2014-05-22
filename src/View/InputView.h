#ifndef Core_InputView_h
#define Core_InputView_h

class InputView
{
public:
    /**
     * Default constructor that creates a new instance of a Controller.
     */
    InputView();
    
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
};

#endif
