#ifndef Core_InputView_h
#define Core_InputView_h

#include "GLFW/glfw3.h"
#include "InputManager.h"
#include "InputState.h"
#include "InputCode.h"
#include "IKeyPressEventHandler.h"
#include "IKeyReleaseEventHandler.h"
#include "set"

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
     * Poll the state of a key. This function may be useful in some circumstances, e.g. synchronizing 
     * the keyboard and game states when the game starts. However, most input should be handled through
     * the more efficient event- based system. 
     */
    InputState GetKeyState(KeyCode keyCode);

    /**
     * Associate an InputManager with this InputView. The InputManager specified here will receive input
     * events from this InputView and will have the ability to poll this InputView for events. 
     * Only one InputManager may be associated with an InputView at a time.
     */
    void SetManager(InputManager* inputManager);

    /**
     * Specify a key to fire an event when the key is pressed. The event will be received by the InputManager
     * associated with this InputView.
     */
    void registerKeyPress(KeyCode keyCode);

    /**
     * If the specified key was previously registered with registerKeyPress, remove the registration and 
     * stop firing events when the key is pressed.
     */
    void deregisterKeyPress(KeyCode keyCode);

    /**
     * Specify a key to fire an event when the key is released. The event will be received by the InputManager
     * associated with this InputView.
     */
    void registerKeyRelease(KeyCode keyCode);

    /**
     * If the specified key was previously registered with registerKeyPress, remove the registration and 
     * stop firing events when the key is released.
     */
    void deregisterKeyRelease(KeyCode keyCode);
    
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

    // Set of keys that fire events when pressed.
    std::set<KeyCode> registeredKeyPressCodes;
    // Set of keys that fire events when released.
    std::set<KeyCode> registeredKeyReleaseCodes;

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
