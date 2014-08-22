#ifndef Core_InputView_h
#define Core_InputView_h

#include "SFML/Window.hpp"
#include "set"

class InputManager;
enum class InputState;
enum class MouseInputMode;
enum class KeyboardKey;
enum class MouseButton;
/**
 * Provides a full set of logic for accessing input.
 */
class InputView
{
public:
    /**
     * Default constructor that creates a new instance of an InputView.
     */
    InputView(sf::Window* window);
    
    /**
     * Initializes the InputView.
     */
    void Initialize();
    
    /**
     * Updates the InputView.
     * @param inputManager InputManager which will receive update information. This InputManager will also receive all input events until the next time this function is called.
     */
    void Update(InputManager* inputManager);

    /**
     * Poll the current state of a key. 
     * @param key Key code to poll.
     * @return the current state of the key.
     */
    InputState GetKeyboardKeyState(KeyboardKey key);

    /**
     * Poll the current state of a mouse button.
     * @param button Mouse button to poll.
     * @return the current state of the mouse button.
     */
    InputState GetMouseButtonState(MouseButton button);

    /**
     * Poll the current horizontal coordinate of the mouse cursor.
     * @return the current x coordinate of the mouse cursor, relative to the game window.
     */
    int GetMouseX();

    /**
     * Poll the current vertical coordinate of the mouse cursor.
     * @return the current y coordinate of the mouse cursor, relative to the game window.
     */
    int GetMouseY();

    /**
     * Event handler for internal SFML events. Acts as a shim between SFML events and native engine events.
     * @param event SFML event, which should be treated as immutable.
     */
    void OnSfmlEvent(sf::Event event);

    /**
     * Set the mouse cursor behavior.
     * @param mode one of the following: 
     * * MouseInputMode::SHOW to set the mouse cursor behavior to default (operating system cursor is visible and cursor may freely move between this game window and other windows.
     * * MouseInputMode::HIDE to set the mouse cursor behavior to hidden and unlocked (operating system cursor is not visible within the game window and cursor may freely move between the game window and other windows. This behavior is desirable for menus which draw their own cursor sprite.
     * * MouseInputMode::HIDE_AND_LOCK to set the mouse cursor behavior to hidden and locked (operating system cursor is not visible within the game window and the cursor is locked to the game window. This behavior is desirable for games which use the mouse in a direct manner, such as for controlling a camera.
     */
    void SetMouseInputMode(MouseInputMode mode);

    /**
     * Get the current mouse cursor behavior.
     * @return the current mouse input mode.
     */
    MouseInputMode GetMouseInputMode();
    
private:
    // Private constructors to disallow access.
    InputView(InputView const &other);
    InputView operator=(InputView other);

    // SFML mouse origin, used for cursor lock hack
    const sf::Vector2i MOUSE_ORIGIN;

    // Game window
    sf::Window* window;

    // InputManager which receives input events.
    InputManager* inputManager;

    // Mouse input mode state
    MouseInputMode mouseInputMode;

    /**
     * Helper method which handles SFML keyboard key press events. Fires a native engine event to the current InputManger.
     * @param event An SFML event to handle.
     */
    void onSfmlKeyPressed(sf::Event::KeyEvent event);

    /**
     * Helper method which handles SFML keyboard key release events. Fires a native engine event to the current InputManger.
     * @param event An SFML event to handle.
     */
    void onSfmlKeyReleased(sf::Event::KeyEvent event);

    /**
     * NOT IMPLEMENTED
     * Helper method which handles SFML mouse wheel events. Fires a native engine event to the current InputManger.
     * @param event An SFML event to handle.
     */
    void onSfmlMouseWheelMoved(sf::Event::MouseWheelEvent event);

    /**
     * Helper method which handles SFML mouse button press events. Fires a native engine event to the current InputManger.
     * @param event An SFML event to handle.
     */
    void onSfmlMouseButtonPressed(sf::Event::MouseButtonEvent event);

    /**
     * Helper method which handles SFML mouse button release events. Fires a native engine event to the current InputManger.
     * @param event An SFML event to handle.
     */
    void onSfmlMouseButtonReleased(sf::Event::MouseButtonEvent event);

    /**
     * Helper method which handles SFML mouse cursor motion events. Fires a native engine event to the current InputManger.
     * @param event An SFML event to handle.
     */
    void onSfmlMouseMoved(sf::Event::MouseMoveEvent event);

    /**
     * NOT IMPLEMENTED
     * Helper method which handles SFML joystick button press events. Fires a native engine event to the current InputManger.
     * @param event An SFML event to handle.
     */
    void onSfmlJoystickButtonPressed(sf::Event::JoystickButtonEvent event);

    /**
     * NOT IMPLEMENTED
     * Helper method which handles SFML joystick button release events. Fires a native engine event to the current InputManger.
     * @param event An SFML event to handle.
     */
    void onSfmlJoystickButtonReleased(sf::Event::JoystickButtonEvent event);

    /**
     * NOT IMPLEMENTED
     * Helper method which handles SFML joystick axis motion events. Fires a native engine event to the current InputManger.
     * @param event An SFML event to handle.
     */
    void onSfmlJoystickMoved(sf::Event::JoystickMoveEvent event);

    /**
     * NOT IMPLEMENTED
     * Helper method which handles SFML joystick connect events. Fires a native engine event to the current InputManger.
     * @param event An SFML event to handle.
     */
    void onSfmlJoystickConnected(sf::Event::JoystickConnectEvent event);

    /**
     * NOT IMPLEMENTED
     * Helper method which handles SFML joystick disconnect events. Fires a native engine event to the current InputManger.
     * @param event An SFML event to handle.
     */
    void onSfmlJoystickDisconnected(sf::Event::JoystickConnectEvent event);
    
    /**
     * NOT IMPLEMENTED
     * Helper method which handles SFML text entry events. Fires a native engine event to the current InputManger.
     * @param event An SFML event to handle.
     */
    void onSfmlTextEntered(sf::Event::TextEvent event);

    /**
     * Utility method to convert SFML key codes to native engine key codes.
     * @param key SFML key code
     * @return corresponding native engine code
     */
    KeyboardKey nativeKeyboardKey(sf::Keyboard::Key key);

    /**
     * Utility method to convert native engine key codes to SFML key codes.
     * @param keyCode native engine key code
     * @return corresponding SFML key code
     */
    sf::Keyboard::Key sfmlKeyboardKey(KeyboardKey key);

    /**
     * Utility method to convert SFML mouse button codes to native engine mouse button codes.
     * @param button SFML mouse button code
     * @return corresponding native engine mouse button code
     */
    MouseButton nativeMouseButton(sf::Mouse::Button button);

    /**
     * Utility method to convert native engine mouse button codes to SFML key codes.
     * @param keyCode native engine mouse button code
     * @return corresponding SFML mouse button code
     */
    sf::Mouse::Button sfmlMouseButton(MouseButton button);
};

#endif
