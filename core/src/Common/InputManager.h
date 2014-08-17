#ifndef Core_InputManager_h
#define Core_InputManager_h

#include "IInputEventHandler.h"
#include "InputState.h"
#include "InputCode.h"
#include "vector"
#include "unordered_map"
#include "set"

class InputView;
class KeyPressEvent;
class KeyReleaseEvent;
class MouseEvent;
class MouseButtonPressEvent;
class MouseButtonReleaseEvent;

enum MouseInputMode
{
    SHOW,
    HIDE,
    HIDE_AND_LOCK
};

class InputManager : public IInputEventHandler
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
     * Register an event handler to receive mouse input events.
     * @param[in] eventHandler Pointer to the IInputEventHandler to register. If the event handler does not have an
     * existing registration with this InputManager, a new registration will be created. Otherwise, this function has
     * no effect.
     */
    void RegisterMouseInputEventHandler(IInputEventHandler* eventHandler);

    /**
     * Deregister an event handler which will no longer receive mouse input events.
     * @param[in] eventHandler Pointer to the IInputEventHandler to deregister. If the event handler has an existing
     * registration with this InputManager, the registration will be removed. Otherwise, this function has no effect.
     */
    void DeregisterMouseInputEventHandler(IInputEventHandler* eventHandler);

    /**
     * Register an event handler to receive keyboard input events.
     * @param[in] handler Pointer to the IInputEventHandler to register. If the handler does not have an existing 
     * registration with this InputManager, a new registration will be created.  Otherwise, the existing registration
     * will be modified.
     * @param[in] keyCodes Vector of key codes corresponding to keyboard keys that the event handler will receive. 
     * If the handler does not have an existing registration with this InputManager, the new registration will
     * be initialized with the contents of this vector. Otherwise, the registration will be updated with the 
     * set union of the contents of this vector and the key codes in the existing registration.
     */
    void RegisterKeyboardInputEventHandler(IInputEventHandler* eventHandler, std::vector<KeyCode>);
    
    /**
     * Deregister a KeyReleaseEventHandler which will no longer receive KeyReleaseEvents.
     * @param[in] handler Pointer to the KeyReleaseEventHandler to deregister. If the handler has an existing registration
     * with this InputManager, the registration will be modified. Otherwise, this function has no effect. 
     * @param[in] keyCodes Vector of key codes int values corresponding to keyboard keys that should no be received
     * by the event handler. If the handler has an existing registration with this InputManager, the registration will 
     * be updated with the relative complement of the contents of this vector with respect to the key codes in the 
     * existing registration. If the result of this operation is an empty set, the handler's registration will be removed 
     * from this InputManager.
     */
    void DeregisterKeyboardInputEventHandler(IInputEventHandler* eventHandler, std::vector<KeyCode>);

    /**
     * True if the given KeyCode has at least one registered release event handler. False otherwise.
     */
    bool IsRegisteredEventHandler(KeyCode* keyCode);

    /**
     * Poll the current state of a key.
     * @param keyCode The keyboard key to poll.
     * @return the current state of the keyboard key.
     * If an invalid key code was passed, KeyState::Invalid is returned.
     */
    InputState GetKeyState(KeyCode keyCode);

    /**
     * Poll the current state of a mouse button.
     * @param mouseCode The mouse button to poll.
     * @return the current state of the mouse button
     */
    InputState GetMouseButtonState(MouseCode mouseCode);

    /**
     * Poll the horixontal coordinate of the mouse cursor. 
     * @return the x coordinate of the mouse cursor within the game window. The left edge of the game window is the origin.
     */
    int GetMouseAbsoluteX();

    /**
     * Poll the vertical coordinate of the mouse cursor.
     * @return the y coordinate of the mouse cursor within the game window. The top edge of the game window is the origin.
     */
    int GetMouseAbsoluteY();

    /**
     * Distributes event to registered event handlers. Should be called only by InputView.
     * @param event event to distribute.
     */
    void OnKeyboardKeyPress(KeyPressEvent* event);
    
    /**
     * Distributes event to registered event handlers. Should be called only by InputView.
     * @param event event to distribute.
     */
    void OnKeyboardKeyRelease(KeyReleaseEvent* event);

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
   
    // Maps of registered keys and their associated handlers. 
    // C++ strong enums are not usable as map keys, so a cast to int is required.
    std::unordered_map<int, std::set<IInputEventHandler*>> registeredKeyboardInputEventHandlers;
    std::vector<IInputEventHandler*> registeredMouseInputEventHandlers;
};

#endif
