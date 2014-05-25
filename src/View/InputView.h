#include "GLFW/glfw3.h"
#include "InputKeyState.h"
#ifndef Core_InputView_h
#define Core_InputView_h

/**
 * Provides a full set of logic for accessing input.
 * 
 * Currently does nothing, though.
 */
class InputView
{
public:
    /**
     * Default constructor that creates a new instance of a Controller.
     */
    InputView(GLFWwindow* window);
    
    /**
     * Initializes the InputView.
     */
    void Initialize(GLFWwindow* window);
    
    /**
     * Updates the InputView.
     */
    void Update();

    /**
     *
     */
    KeyState GetKeyState(int keyCode);


private:
    // Private constructors to disallow access.
    InputView(InputView const &other);
    InputView operator=(InputView other);

    GLFWwindow* window;

    /**
     * Converts a GLFW key code to an engine keycode.
     */
    int keyCode(int glfwKeyCode);

    /**
     * Converts an engine key code to a GLFW keycode.
     */
    int glfwKeyCode(int keyCode);
};

#endif
