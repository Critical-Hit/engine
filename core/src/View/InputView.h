#ifndef Core_InputView_h
#define Core_InputView_h

#include "SFML/Window.hpp"
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
    InputView(sf::Window* window);
    
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

    InputState GetMouseButtonState(MouseCode mouseCode);

    int GetMouseAbsoluteX();

    int GetMouseAbsoluteY();

    void OnSfmlEvent(sf::Event event);

    void SetMouseInputMode(MouseInputMode mode);

    MouseInputMode GetMouseInputMode();
    
private:
    // Private constructors to disallow access.
    InputView(InputView const &other);
    InputView operator=(InputView other);

    sf::Window* window;

    // InputManager which receives input events.
    InputManager* inputManager;

    void onSfmlKeyPressed(sf::Event::KeyEvent event);

    void onSfmlKeyReleased(sf::Event::KeyEvent event);

    void onSfmlMouseWheelMoved(sf::Event::MouseWheelEvent event);

    void onSfmlMouseButtonPressed(sf::Event::MouseButtonEvent event);

    void onSfmlMouseButtonReleased(sf::Event::MouseButtonEvent event);

    void onSfmlMouseMoved(sf::Event::MouseMoveEvent event);

    void onSfmlJoystickButtonPressed(sf::Event::JoystickButtonEvent event);

    void onSfmlJoystickButtonReleased(sf::Event::JoystickButtonEvent event);

    void onSfmlJoystickMoved(sf::Event::JoystickMoveEvent event);

    void onSfmlJoystickConnected(sf::Event::JoystickConnectEvent event);

    void onSfmlJoystickDisconnected(sf::Event::JoystickConnectEvent event);
    
    void onSfmlTextEntered(sf::Event::TextEvent event);

    KeyCode keyCode(sf::Keyboard::Key sfmlKey);

    sf::Keyboard::Key sfmlKeyCode(KeyCode keyCode);

    MouseCode mouseCode(sf::Mouse::Button sfmlMouseButton);

    sf::Mouse::Button sfmlMouseMacro(MouseCode mouseCode);

    InputState keyState(int glfwInputState);

    MouseInputMode mouseInputMode;

    const sf::Vector2i MOUSE_ORIGIN;
};

#endif
