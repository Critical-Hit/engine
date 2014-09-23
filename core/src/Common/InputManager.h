#ifndef Core_InputManager_h
#define Core_InputManager_h

#include "KeyboardKey.h"
#include "MouseButton.h"
#include "JoystickAxis.h"
#include <unordered_map>
#include <map>
#include <functional>
#include <memory>

class InputView;
class KeyboardKeyPressEvent;
class KeyboardKeyReleaseEvent;
class MouseEvent;
class MouseButtonPressEvent;
class MouseButtonReleaseEvent;
class JoystickButtonPressEvent;
class JoystickButtonReleaseEvent;
class JoystickAxisEvent;
enum class InputState;

enum class MouseInputMode
{
    SHOW,
    HIDE,
    HIDE_AND_LOCK
};

class InputManager
{
public:
    typedef std::function<void (MouseEvent)> MouseMotionHandler;
    typedef std::function<void (MouseButtonPressEvent)> MouseButtonPressHandler;
    typedef std::function<void (MouseButtonReleaseEvent)> MouseButtonReleaseHandler;
    typedef std::function<void (KeyboardKeyPressEvent)> KeyboardKeyPressHandler;
    typedef std::function<void (KeyboardKeyReleaseEvent)> KeyboardKeyReleaseHandler;
    typedef std::function<void (JoystickButtonPressEvent)> JoystickButtonPressHandler;
    typedef std::function<void (JoystickButtonReleaseEvent)> JoystickButtonReleaseHandler;
    typedef std::function<void (JoystickAxisEvent)> JoystickMotionHandler;

    /**
     * Default constructor that creates a new instance of a InputManager.
     */
    InputManager();

    ~InputManager();

    void Update();

    /**
     * Associate an InputView with this InputManager. The InputView specified here will be used to poll input state on demand. 
     * Only one InputView may be associated with an InputManager at a time.
     * @param inputView InputView to associated with this InputManager
     */
    void SetView(std::shared_ptr<InputView> inputView);

    /**
     * Set the mouse cursor behavior.
     * @param mode one of the following:
     * * MouseInputMode::SHOW - Draw the operating system cursor.
     * * MouseInputMode::HIDE - Hide the operating system cursor.
     * * MouseInputMode::HIDE_AND_LOCK - Hide the operating system cursor and lock the cursor to the game window.
     */
    void SetMouseInputMode(MouseInputMode mode);

    /**
     * Get the current mouse cursor behavior.
     * @return one of the following:
     * * MouseInputMode::SHOW - The operating system cursor is being drawn.
     * * MouseInputMode::HIDE - The operating system cursor is hidden.
     * * MouseInputMode::HIDE_AND_LOCK - The operating system cursor is hidden and the cursor is locked to the game window.
     */
    MouseInputMode GetMouseInputMode();

    /**
     * Register a function to handle mouse input.
     * @param handler A function which will receive and handler MouseEvents when the mouse cursor is moved.
     * Any existing handler will be overwritten.
     */
    void RegisterMouseMotionHandler(MouseMotionHandler handler);

    /**
     * Register a function to handle mouse button presses.
     * @param button A mouse button.
     * @param handler A function which will receive and handle MouseButtonPressEvents when the specified mouse button is pressed.
     * Any existing handler for the specified mouse button will be overwritten.
     */
    void RegisterMouseButtonPressHandler(MouseButton button, MouseButtonPressHandler handler);

    /**
     * Register a function to handle mouse button releases.
     * @param button A mouse button.
     * @param handler A function which will receive and handle MouseButtonReleaseEvents when the specified mouse button is released.
     * Any existing handler for the specified mouse button will be overwritten.
     */
    void RegisterMouseButtonReleaseHandler(MouseButton button, MouseButtonReleaseHandler handler);

    /**
     * Register a function to handle keyboard key presses.
     * @param key A keyboard key.
     * @param handler A function which will receive and handle KeyboardKeyPressEvents when the specified key is pressed.
     * Any existing handler for the specified key will be overwritten.
     */
    void RegisterKeyboardKeyPressHandler(KeyboardKey key, KeyboardKeyPressHandler handler);

    /**
     * Register a function to handle keyboard key releases.
     * @param key A keyboard key.
     * @param handler A function which will receive and handle KeyboardKeyPressEvents when the specified key is released.
     * Any existing handler for the specified key will be overwritten.
     */
    void RegisterKeyboardKeyReleaseHandler(KeyboardKey key, KeyboardKeyReleaseHandler handler);
    
    /**
     * Register a function to handle joystick button presses.
     * @param joystick A joystick id
     * @param button A button id
     * @param handler A function which will receive and handle JoystickButtonPressEvents when the specified button of the specified joystick is pressed.
     * Any existing handler for the specified joystick button will be overwritten.
     */
    void RegisterJoystickButtonPressHandler(unsigned int joystick, unsigned int button, JoystickButtonPressHandler handler);

    
    /**
     * Register a function to handle joystick button releases.
     * @param joystick A joystick id
     * @param button A button id
     * @param handler A function which will receive and handle JoystickButtonReleaseEvents when the specified button of the specified joystick is released.
     * Any existing handler for the specified joystick button will be overwritten.
     */
    void RegisterJoystickButtonReleaseHandler(unsigned int joystick, unsigned int button, JoystickButtonReleaseHandler handler);

    /**
     * Register a function to handle joystick axis input, such as the analog inputs and point-of-view hat.
     * @param joystick A joystick id
     * @param button A button id
     * @param handler A function which will receive and handle JoysticAxisInputEvents when the specified axis of the specified joystick is moved.
     * Any existing handler for the specified joystick axis will be overwritten.
     */
    void RegisterJoystickMotionHandler(unsigned int joystick, JoystickAxis axis, JoystickMotionHandler handler);

    /**
     * Remove any existing mouse input handler.
     */
    void DeregisterMouseMotionHandler();   
 
    /**
     * Remove any existing mouse button press handler for the specified button.
     * @param button A mouse button.
     */
    void DeregisterMouseButtonPressHandler(MouseButton button);

    /**
     * Remove any existing mouse button release handler for the specified button.
     * @param button A mouse button.
     */
    void DeregisterMouseButtonReleaseHandler(MouseButton button);

    /**
     * Remove any existing keyboard key press handler for the specified key.
     * @param key A keyboard key.
     */
    void DeregisterKeyboardKeyPressHandler(KeyboardKey key);

    /**
     * Remove any existing keyboard key release handler for the specified key.
     * @param key A keyboard key.
     */
    void DeregisterKeyboardKeyReleaseHandler(KeyboardKey key);

    /**
     * Remove any existing joystick button press handler for the specified joystick button.
     * @param joystick A joystick id
     * @param button A button id
     */
    void DeregisterJoystickButtonPressHandler(unsigned int joystick, unsigned int button);

    /**
     * Remove any existing joystick button press handler for the specified joystick button.
     * @param joystick A joystick id
     * @param button A button id
     */
    void DeregisterJoystickButtonReleaseHandler(unsigned int joystick, unsigned int button);

    /**
     * Remove any existing joystick axis motion handler for the specified joystick axis
     * @param joystick A joystick id
     * @param axis A joystick axis
     */
    void DeregisterJoystickMotionHandler(unsigned int joystick, JoystickAxis axis);

    /**
     * True if the given KeyboardKey has at least one registered release event handler. False otherwise.
     */
    bool IsRegisteredEventHandler(KeyboardKey key);

    /**
     * Poll the current state of a key.
     * @param key The keyboard key to poll.
     * @return the current state of the keyboard key.
     * If an invalid key code was passed, InputState::INVALID is returned.
     */
    InputState GetKeyState(KeyboardKey key);

    /**
     * Poll the current state of a mouse button.
     * @param button The mouse button to poll.
     * @return the current state of the mouse button
     */
    InputState GetMouseButtonState(MouseButton button);

    /**
     * Poll the horizontal coordinate of the mouse cursor. 
     * @return the x coordinate of the mouse cursor within the game window. The left edge of the game window is the origin.
     */
    int GetMouseX();

    /**
     * Poll the vertical coordinate of the mouse cursor.
     * @return the y coordinate of the mouse cursor within the game window. The top edge of the game window is the origin.
     */
    int GetMouseY();

    /**
     * Poll the current state of a joystick button.
     * @param joystick The id of the joystick to poll.
     * @param button The id of the button to poll.
     * @return The current state of the joystick button. If the joystick is disconnected, InputState::RELEASED is returned.
     */
    InputState GetJoystickButtonState(unsigned int joystick, unsigned int button);

    /**
     * Poll the current value of a joystick axis.
     * @param joystick The id of the joystick to poll.
     * @param axis The joystick axis to poll.
     * @return The current value of the joystick button. -100.0 is the minimum value, 0.0 is the center, and 100.0 is the
     * maximum value. If the joystick is disconnected, 0.0 is returned.
     */
    float GetJoystickAxisValue(unsigned int joystick, JoystickAxis axis);

    /**
     * Distributes event to registered event handlers. Should be called only by InputView.
     * @param event event to distribute.
     */
    void OnKeyboardKeyPress(KeyboardKeyPressEvent event);
    
    /**
     * Distributes event to registered event handlers. Should be called only by InputView.
     * @param event event to distribute.
     */
    void OnKeyboardKeyRelease(KeyboardKeyReleaseEvent event);

    /**
     * Distributes event to registered event handlers. Should be called only by InputView.
     * @param event event to distribute.
     */
    void OnMouseButtonPress(MouseButtonPressEvent event);

    /**
     * Distributes event to registered event handlers. Should be called only by InputView.
     * @param event event to distribute.
     */
    void OnMouseButtonRelease(MouseButtonReleaseEvent event);

    /**
     * Distributes event to registered event handlers. Should be called only by InputView.
     * @param event event to distribute.
     */
    void OnJoystickButtonPress(JoystickButtonPressEvent event);

    /**
     * Distributes event to registered event handlers. Should be called only by InputView.
     * @param event event to distribute.
     */
    void OnJoystickButtonRelease(JoystickButtonReleaseEvent event);

    /**
     * Distributes event to registered event handlers. Should be called only by InputView.
     * @param event event to distribute.
     */
    void OnJoystickAxisInput(JoystickAxisEvent event);

    /**
     * Distributes event to registered event handlers. Should be called only by InputView.
     * @param event event to distribute.
     */
    void OnMouseInput(MouseEvent event);
    
private:
    // Private constructors to disallow access.
    InputManager(InputManager const &other);
    InputManager operator=(InputManager other);

    // InputView which is polled for ondemand input.
    std::weak_ptr<InputView> inputView;
    
    // Registered event handlers
    // map is used here instead of unordered_map due to compatibility with enum keys
    MouseMotionHandler mouseMotionHandler;
    std::map<MouseButton, MouseButtonPressHandler> mouseButtonPressHandlers;
    std::map<MouseButton, MouseButtonReleaseHandler> mouseButtonReleaseHandlers;
    std::map<KeyboardKey, KeyboardKeyPressHandler> keyboardKeyPressHandlers;
    std::map<KeyboardKey, KeyboardKeyReleaseHandler> keyboardKeyReleaseHandlers;
    // first uint is joystick id, second uint is button
    std::unordered_map<unsigned int, std::unordered_map<unsigned int, JoystickButtonPressHandler>> joystickButtonPressHandlers;
    std::unordered_map<unsigned int, std::unordered_map<unsigned int, JoystickButtonReleaseHandler>> joystickButtonReleaseHandlers;
    std::unordered_map<unsigned int, std::map<JoystickAxis, JoystickMotionHandler>> joystickMotionHandlers;
};

#endif
