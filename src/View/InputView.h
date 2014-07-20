#ifndef Core_InputView_h
#define Core_InputView_h

#include "GLFW/glfw3.h"
#include "InputManager.h"
#include "InputState.h"
#include "InputCode.h"
#include "IKeyPressEventHandler.h"
#include "IKeyReleaseEventHandler.h"
#include "set"
#include "ControllerPackage.h"

class InputManager;

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
    InputView(GLFWwindow* window);
    
    /**
     * Initializes the InputView.
     */
    void Initialize();
    
    /**
     * Updates the InputView.
     */
    void Update(InputManager* inputManager);

    /**
     * Poll the state of a key. This function may be useful in some circumstances, e.g. synchronizing 
     * the keyboard and game states when the game starts. However, most input should be handled through
     * the more efficient event- based system. 
     */
    InputState GetKeyState(KeyCode keyCode);
    
    /**
     * Function conforming to GLFWkeyfun typedef. Used to couple with GLFW callback system.
     */
    void keyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);

private:
    /**
     * Workaround for using C++ callbacks with GLFW.
     * See: http://www.glfw.org/faq.html#how-do-i-use-c-methods-as-callbacks
     */
    static InputView* instance;

    /**
     * Workaround for using C++ callbacks with GLFW.
     * See: http://www.glfw.org/faq.html#how-do-i-use-c-methods-as-callbacks
     */
    static void keyCallbackDispatcher(GLFWwindow* window, int key, int scanCode, int action, int mods);

    // Private constructors to disallow access.
    InputView(InputView const &other);
    InputView operator=(InputView other);

    GLFWwindow* window;

    // InputManager which receives input events.
    InputManager* inputManager;

    /**
     * Converts a GLFW key code to an engine keycode.
     */
    KeyCode keyCode(int glfwKeyCode);

    /**
     * Converts an engine key code to a GLFW keycode.
     */
    int glfwKeyCode(KeyCode keyCode);

    /**
     * Converts a GLFW input state to an engine input state.
     */
    InputState keyState(int glfwInputState);
};

#endif
