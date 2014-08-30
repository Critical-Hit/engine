#ifndef Core_InputManager_h
#define Core_InputManager_h

#include "KeyboardKey.h"
#include "MouseButton.h"
#include <vector>
#include <map>
#include <functional>

class InputView;
class KeyboardKeyPressEvent;
class KeyboardKeyReleaseEvent;
class MouseEvent;
class MouseButtonPressEvent;
class MouseButtonReleaseEvent;
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
    void SetView(InputView* inputView);

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
    void RegisterMouseMotionHandler(std::function<void (MouseEvent*)> handler);

    /**
     * Register a function to handle mouse button presses.
     * @param button A mouse button.
     * @param handler A function which will receive and handle MouseButtonPressEvents when the specified mouse button is pressed.
     * Any existing button press handler for the specified mouse button will be overwritten.
     */
    void RegisterMouseButtonPressHandler(MouseButton button, std::function<void (MouseButtonPressEvent*)> handler);

    /**
     * Register a function to handle mouse button releases.
     * @param button A mouse button.
     * @param handler A function which will receive and handle MouseButtonReleaseEvents when the specified mouse button is released.
     * Any existing button released handler for the specified mouse button will be overwritten.
     */
    void RegisterMouseButtonReleaseHandler(MouseButton button, std::function<void (MouseButtonReleaseEvent*)> handler);

    /**
     * Register a function to handle keyboard key presses.
     * @param key A keyboard key.
     * @param handler A function which will receive and handle KeyboardKeyPressEvents when the specified key is pressed.
     * Any existing key press handler for the specified key will be overwritten.
     */
    void RegisterKeyboardKeyPressHandler(KeyboardKey key, std::function<void (KeyboardKeyPressEvent*)> handler);

    /**
     * Register a function to handle multiple keyboard key presses.
     * @param keys The vector of keyboard keys.
     * @param handler A function which will receive and handle KeyboardKeyPressEvents when the specified key is pressed.
     * Any existing key press handler for the specified key will be overwritten.
     */
    void RegisterKeyboardKeyPressHandler(std::vector<KeyboardKey> keys, std::function<void (KeyboardKeyPressEvent*)> handler);
    
    /**
     * Register a function to handle keyboard key presses.
     * @param key A keyboard key.
     * @param handler A function which will receive and handle KeyboardKeyPressEvents when the specified key is pressed.
     * Any existing key release handler for the specified key will be overwritten.
     */
    void RegisterKeyboardKeyReleaseHandler(KeyboardKey key, std::function<void (KeyboardKeyReleaseEvent*)> handler);
    
    /**
     * Register a function to handle keyboard key presses.
     * @param keys The vector of keyboard keys.
     * @param handler A function which will receive and handle KeyboardKeyPressEvents when the specified key is pressed.
     * Any existing key release handler for the specified key will be overwritten.
     */
    void RegisterKeyboardKeyReleaseHandler(std::vector<KeyboardKey> keys, std::function<void (KeyboardKeyReleaseEvent*)> handler);
    
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
     * Remove any existing keyboard key press handler for the specified button.
     * @param key A keyboard key.
     */
    void DeregisterKeyboardKeyPressHandler(KeyboardKey key);

    /**
     * Remove any existing keyboard key release handler for the specified button.
     * @param key A keyboard key.
     */
    void DeregisterKeyboardKeyReleaseHandler(KeyboardKey key);

    /**
     * Remove any existing keyboard key press handler for the specified keys.
     * @param keys A vector of keyboard keys.
     */
    void DeregisterKeyboardKeyPressHandler(std::vector<KeyboardKey> keys);
    
    /**
     * Remove any existing keyboard key release handler for the specified keys.
     * @param keys A vector of keyboard keys.
     */
    void DeregisterKeyboardKeyReleaseHandler(std::vector<KeyboardKey> keys);
    
    /**
     * True if the given KeyboardKey has at least one registered release event handler. False otherwise.
     */
    bool IsRegisteredEventHandler(KeyboardKey key);

    /**
     * Poll the current state of a key.
     * @param key The keyboard key to poll.
     * @return the current state of the keyboard key.
     * If an invalid key code was passed, KeyState::Invalid is returned.
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
     * Distributes event to registered event handlers. Should be called only by InputView.
     * @param event event to distribute.
     */
    void OnKeyboardKeyPress(KeyboardKeyPressEvent* event);
    
    /**
     * Distributes event to registered event handlers. Should be called only by InputView.
     * @param event event to distribute.
     */
    void OnKeyboardKeyRelease(KeyboardKeyReleaseEvent* event);

    /**
     * Distributes event to registered event handlers. Should be called only by InputView.
     * @param event event to distribute.
     */
    void OnMouseInput(MouseEvent* event);

    /**
     * Distributes event to registered event handlers. Should be called only by InputView.
     * @param event event to distribute.
     */
    void OnMouseButtonPress(MouseButtonPressEvent* event);

    /**
     * Distributes event to registered event handlers. Should be called only by InputView.
     * @param event event to distribute.
     */
    void OnMouseButtonRelease(MouseButtonReleaseEvent* event);
    
    /**
    * Sets all variables of this instance to match the other instance.
    * @param other InputManager to copy attributes from.
    */
    void CopyFrom(InputManager* other);

private:
    // Private constructors to disallow access.
    InputManager(InputManager const &other);
    InputManager operator=(InputManager other);

    // InputView which is polled for ondemand input.
    InputView* inputView;
    
    // Registered event handlers
    std::function<void (MouseEvent*)> mouseMotionHandler;
    std::map<MouseButton, std::function<void (MouseButtonPressEvent*)>> mouseButtonPressHandlers;
    std::map<MouseButton, std::function<void (MouseButtonReleaseEvent*)>> mouseButtonReleaseHandlers;
    std::map<KeyboardKey, std::function<void (KeyboardKeyPressEvent*)>> keyboardKeyPressHandlers;
    std::map<KeyboardKey, std::function<void (KeyboardKeyReleaseEvent*)>> keyboardKeyReleaseHandlers;
};

#endif
