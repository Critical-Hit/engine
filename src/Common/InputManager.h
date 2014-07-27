#ifndef Core_InputManager_h
#define Core_InputManager_h

#include "InputView.h"
#include "IInputEventHandler.h"
#include "InputState.h"
#include "InputCode.h"
#include "vector"
#include "unordered_map"
#include "set"

class InputView;
class KeyPressEvent;
class KeyReleaseEvent;
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
     * Associate an InputView with this InputManager. The InputView specified 
     * here will be used to poll input state on demand. 
     * Only one InputView may be associated with an InputManager at a time.
     */
    void SetView(InputView* inputView);

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
     * @param keyCode Key code corresponding to a keyboard key.
     * @return InputState indicating the current state of a key.
     * If an invalid key code was passed, KeyState::Invalid is returned.
     */
    InputState GetKeyState(KeyCode keyCode);

    /**
     * Implemented from IKeyPressEventHandler. Distributes event to registered event handlers.
     * Should be called only by InputView.
     */
    void OnKeyboardKeyPress(KeyPressEvent* event);
    
    /**
     * Implemented from IKeyReleaseEventHandler. Distributes event to registered event handlers.
     * Should be called only by InputView.
     */
    void OnKeyboardKeyRelease(KeyReleaseEvent* event);

    /**
     * Implemented from IMouseEventHandler. Distributes event to registered event handlers.
     * Should be called only by InputView.
     */
    void OnMouseInput(MouseEvent* event);

    /**
     * Implemented from IMouseButtonPressEventHandler. Distributes event to registered event handlers.
     * Should be called only by InputView.
     */
    void OnMouseButtonPress(MouseButtonPressEvent* event);

    /**
     * Implemented from IMouseButtonReleaseEventHandler. Distributes event to registered event handlers.
     * Should be called only by InputView.
     */
    void OnMouseButtonRelease(MouseButtonReleaseEvent* event);
    
	/**
	* Sets all variables of this instance to match the other instance.
	*/
	void CopyFrom(InputManager* other);

private:
    // Private constructors to disallow access.
    InputManager(InputManager const &other);
    InputManager operator=(InputManager other);

    // InputView which fires input events.
    InputView* inputView;
   
    // Maps of registered keys and their associated handlers. 
    // C++ strong enums are not usable as map keys, so a cast to int is required.
    std::unordered_map<int, std::set<IInputEventHandler*>> registeredKeyboardInputEventHandlers;
    std::vector<IInputEventHandler*> registeredMouseInputEventHandlers;
};

#endif
