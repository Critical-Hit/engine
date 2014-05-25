#include "InputKeyStates.h"
#include "vector"
#include "map"
#include "unordered_map"
#ifndef Core_InputManager_h
#define Core_InputManager_h

class InputManager
{
public:

    /**
     * Default constructor that creates a new instance of a InputManager..
     */
    InputManager();

    /**
     * Register a KeyPressEventHandler to receive KeyPressEvents.
     * @param[in] handler Pointer to the KeyPressEventHandler to register. If
     * the handler does not have an existing registration with this InputManager,
     * a new registration will be created. If the handler has an existing 
     * registration with this InputManager, the existing registration will be modified.
     * @param[in] keyCodes Vector of key code int values corresponding to keyboard keys
     * that should cause KeyPressEvents to be fired when pressed. If the handler does not
     * have an existing registration with this InputManager, the new registration will
     * be initialized with the contents of this vector. If the handler has an existing
     * registration with this InputManager, the registration will be updated with the 
     * set union of the contents of this vector and the key codes in the existing
     * registration.
     */
    void RegisterKeyPressEventHandler(IKeyPressEventHandler* handler, std::vector<int> keyCodes);

    /**
     * Deregister a KeyPressEventHandler which will no longer receive KeyPressEvents.
     * @param[in] handler Pointer to the KeyPressEventHandler to deregister. 
     * If the handler does not have an existing registration with this InputManager, 
     * this function has no effect. 
     * @param[in] keyCodes Vector of key codes int values corresponding to keyboard keys
     * that should no longer cause KeyPressEvents to be fired when pressed. If the handler
     * has an existing registration with this InputManager, the registration will be updated
     * with the relative complement of the contents of this vector with respect to the key codes
     * in the existing registration. If the result of this operation is an empty set, the handler's
     * registration will be removed from this InputManager.
     */
    void DeregisterKeyPressEventHandler(IKeyPressEventHandler* handler, std::vector<int> keyCodes);

    /**
     * Register a KeyReleaseEventHandler to receive KeyReleaseEvents..
     * @param[in] handler Pointer to the KeyReleaseEventHandler to register. If
     * the handler does not have an existing registration with this InputManager,
     * a new registration will be created. If the handler has an existing 
     * registration with this InputManager, the existing registration will be modified.
     * @param[in] keyCodes Vector of key code int values corresponding to keyboard keys
     * that should cause KeyReleaseEvents to be fired when released. If the handler does not
     * have an existing registration with this InputManager, the new registration will
     * be initialized with the contents of this vector. If the handler has an existing
     * registration with this InputManager, the registration will be updated with the 
     * set union of the contents of this vector and the key codes in the existing
     * registration.
     */
    void RegisterKeyReleaseEventHandler(IKeyReleaseEventHandler* handler, std::vector<int> keyCodes);

    /**
     * Deregister a KeyReleaseEventHandler which will no longer receive KeyReleaseEvents.
     * @param[in] handler Pointer to the KeyReleaseEventHandler to deregister. 
     * If the handler does not have an existing registration with this InputManager, 
     * this function has no effect. 
     * @param[in] keyCodes Vector of key codes int values corresponding to keyboard keys
     * that should no longer cause KeyReleaseEvents to be fired when released. If the handler
     * has an existing registration with this InputManager, the registration will be updated
     * with the relative complement of the contents of this vector with respect to the key codes
     * in the existing registration. If the result of this operation is an empty set, the handler's
     * registration will be removed from this InputManager.
     */
    void DeregisterKeyReleaseEventHandler(IKeyReleaseEventHandler* handler, std::vector<int> keyCodes);

    /**
     * Poll the last known state of a key.
     * @param keyCode Key code corresponding to a keyboard key.
     * @return KeyState indicating the last known state of a key.
     * If an invalid key code was passed, KeyState::Invalid is returned.
     */
    KeyState LastKeyState(int keyCode);


    void Update();

private:
    // Private constructors to disallow access.
    InputManager(InputManager const &other);
    InputManager operator=(InputManager other);
   
    // Pointer to the InputView we use to access input devices.
    InputView* view;

    // State model of keyboard keys: Map key codes to states.
    // We used map here for iteration performance.
    std::map<int, KeyState> keyStates;

    // Registration models: Map keycodes to containers of event handlers.
    // We used unordered_map here for random access performance.
    std::unordered_map<int, std::vector<IKeyPressEventHandler*>> registeredKeyPressEventHandlers;
    std::unordered_map<int, std::vector<IKeyReleaseEventHandler*>> registeredKeyReleaseEventHandlers;

};

#endif
