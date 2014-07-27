#ifndef Core_InputView_h
#define Core_InputView_h

#include "GLFW/glfw3.h"
#include "InputManager.h"
#include "InputState.h"
#include "InputCode.h"
#include "IInputEventHandler.h"
#include "set"
#include "ControllerPackage.h"

/**
 * Provides a full set of logic for accessing input.
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
     * Set the mouse cursor behavior.
     * @param mode one of the following:
     *        MouseInputMode::SHOW - Draw the operating system cursor.
     *        MouseInputMode::HIDE - Hide the operating system cursor.
     *        MouseInputMode::HIDE_AND_LOCK - Hide the operating system cursor and lock the cursor to the game window.
     */
    void SetMouseInputMode(MouseInputMode mode);

    /**
     * Get the current mouse cursor behavior.
     * @return one of the following:
     *         MouseInputMode::SHOW - The operating system cursor is being drawn.
     *         MouseInputMode::HIDE - The operating system cursor is hidden.
     *         MouseInputMode::HIDE_AND_LOCK - The operating system cursor is hidden and the cursor is locked to the game window.
     */
    MouseInputMode GetMouseInputMode();
    
    /**
     * Function conforming to GLFWkeyfun typedef. Used to couple with GLFW callback system for
     * event-based keyboard input.
     */
    void keyboardCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);
    
    /**
     * Function conforming to GLFWcursorposfun typedef. Used to couple with GLFW callback system
     * for event-based cursor position updates.
     */
    void mouseCallback(GLFWwindow* window, double xpos, double ypos);

    /**
     * Function conforming to GLFWmousebuttonfun typedef. Used to couple with GLFW callback system
     * for event-based mouse button input.
     */
    void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

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
    static void keyboardCallbackDispatcher(GLFWwindow* window, int key, int scanCode, int action, int mods);

    /**
     * Workaround for using C++ callbacks with GLFW.
     * See: http://www.glfw.org/faq.html#how-do-i-use-c-methods-as-callbacks
     */
    static void mouseCallbackDispatcher(GLFWwindow* window, int xpos, int ypos);

    /**
     * Workaround for using C++ callbacks with GLFW.
     * See: http://www.glfw.org/faq.html#how-do-i-use-c-methods-as-callbacks
     */
    static void mouseButtonCallbackDispatcher(GLFWwindow* window, int button, int action, int mods);

    // Private constructors to disallow access.
    InputView(InputView const &other);
    InputView operator=(InputView other);

    GLFWwindow* window;

    // InputManager which receives input events.
    InputManager* inputManager;

    /**
     * Converts a GLFW keyboard key macro to an engine keycode.
     */
    KeyCode keyCode(int glfwKeyCode);

    /**
     * Converts an engine key code to a GLFW keyboard key macro.
     */
    int glfwKeyCode(KeyCode keyCode);

    /**
     * Converts a GLFW mouse macro to an engine MouseCode.
     */
    MouseCode mouseCode(int glfwMouseMacro);

    /**
     * Converts an engine MouseCode to a GLFW mouse macro.
     */
    int glfwMouseMacro(MouseCode glfwMouseMacro);

    /**
     * Converts a GLFW input state to an engine input state macro.
     */
    InputState keyState(int glfwInputState);
};

#endif
