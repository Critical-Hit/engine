#ifndef Core_InputView_h
#define Core_InputView_h
#include "GLFW/glfw3.h"
#include "InputManager.h"
#include "InputKeyState.h"
#include "InputCode.h"
#include "IKeyPressEventHandler.h"
#include "IKeyReleaseEventHandler.h"
#include "set"

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
    KeyState GetKeyState(KeyCode keyCode);

    void setManager(InputManager* inputManager);

    void registerKeyPress(KeyCode keyCode);

    void deregisterKeyPress(KeyCode keyCode);

    void registerKeyRelease(KeyCode keyCode);

    void deregisterKeyRelease(KeyCode keyCode);
    
    static InputView* instance;
    
    void keyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);
private:
    // Private constructors to disallow access.
    InputView(InputView const &other);
    InputView operator=(InputView other);

    GLFWwindow* window;
    InputManager* inputManager;

    std::set<KeyCode> registeredKeyPressCodes;
    std::set<KeyCode> registeredKeyReleaseCodes;

    /**
     * Converts a GLFW key code to an engine keycode.
     */
    KeyCode keyCode(int glfwKeyCode);

    /**
     * Converts an engine key code to a GLFW keycode.
     */
    int glfwKeyCode(KeyCode keyCode);

    bool isKeyPressed(KeyCode keyCode);

    bool isKeyReleased(KeyCode keyCode);

    static void keyCallbackDispatcher(GLFWwindow* window, int key, int scanCode, int action, int mods);
};

#endif
