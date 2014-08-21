#include "InputView.h"
#include "InputManager.h"
#include "InputState.h"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"
#include "KeyboardKeyPressEvent.h"
#include "KeyboardKeyReleaseEvent.h"
#include "MouseEvent.h"
#include "MouseButtonPressEvent.h"
#include "MouseButtonReleaseEvent.h"
#include "MouseButton.h"
#include "KeyboardKey.h"
#include "assert.h"
#include "set"
#include "vector"

sf::Vector2i MOUSE_ORIGIN = sf::Vector2i(0, 0);

InputView::InputView(sf::Window* window)
{
    this->window = window;
    this->inputManager = nullptr;
}

void InputView::Initialize()
{
    this->SetMouseInputMode(MouseInputMode::SHOW);
}

void InputView::Update(InputManager* inputManager)
{
    this->inputManager = inputManager;
}

void InputView::SetMouseInputMode(MouseInputMode mode)
{
    this->mouseInputMode = mode;
    if (mode == MouseInputMode::SHOW)
    {
        this->window->setMouseCursorVisible(true);
    }
    else
    {
        this->window->setMouseCursorVisible(false);
    }
}

MouseInputMode InputView::GetMouseInputMode()
{
    return this->mouseInputMode;
}

void InputView::OnSfmlEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        onSfmlKeyPressed(event.key);
    }
    else if (event.type == sf::Event::KeyReleased)
    {
        onSfmlKeyReleased(event.key);
    }
    else if (event.type == sf::Event::MouseWheelMoved)
    {
        onSfmlMouseWheelMoved(event.mouseWheel);
    }
    else if (event.type == sf::Event::MouseMoved)
    {
        onSfmlMouseMoved(event.mouseMove);
    }
    else if (event.type == sf::Event::JoystickButtonPressed)
    {
        onSfmlJoystickButtonPressed(event.joystickButton);
    }
    else if (event.type == sf::Event::JoystickButtonReleased)
    {
        onSfmlJoystickButtonReleased(event.joystickButton);
    }
    else if (event.type == sf::Event::JoystickConnected)
    {
        onSfmlJoystickConnected(event.joystickConnect);
    }
    else if (event.type == sf::Event::JoystickDisconnected)
    {
        onSfmlJoystickDisconnected(event.joystickConnect);
    }
    else if (event.type == sf::Event::TextEntered)
    {
        onSfmlTextEntered(event.text);
    }
}

void InputView::onSfmlKeyPressed(sf::Event::KeyEvent event)
{
    if (inputManager != nullptr) 
    {
        KeyboardKey key = InputView::keyCode(event.code);
        if (inputManager->IsRegisteredEventHandler(&key))
        {
            KeyboardKeyPressEvent nativeEvent(&key);
            this->inputManager->OnKeyboardKeyPress(&nativeEvent);
        }
    }
}

void InputView::onSfmlKeyReleased(sf::Event::KeyEvent event)
{
    if (inputManager != nullptr) 
    {
        KeyboardKey key = InputView::keyCode(event.code);
        if (inputManager->IsRegisteredEventHandler(&key))
        {
            KeyboardKeyReleaseEvent event(&key);
            this->inputManager->OnKeyboardKeyRelease(&event);
        }
    }
}

void InputView::onSfmlMouseWheelMoved(sf::Event::MouseWheelEvent event)
{
    // TODO: mouse wheel input handling
}

void InputView::onSfmlMouseButtonPressed(sf::Event::MouseButtonEvent event)
{
    if (inputManager != nullptr) 
    {
        MouseButton button = InputView::mouseCode(event.button);
        MouseButtonPressEvent nativeEvent(event.x, event.y, button);
        this->inputManager->OnMouseButtonPress(&nativeEvent);
    }
}

void InputView::onSfmlMouseButtonReleased(sf::Event::MouseButtonEvent event)
{
    if (inputManager != nullptr)
    {
        MouseButton button = InputView::mouseCode(event.button);
        MouseButtonReleaseEvent nativeEvent(event.x, event.y, button);
        this->inputManager->OnMouseButtonRelease(&nativeEvent);
    }
}

void InputView::onSfmlMouseMoved(sf::Event::MouseMoveEvent event)
{
    if (inputManager != nullptr)
    {
        MouseEvent nativeEvent(event.x, event.y);
        this->inputManager->OnMouseInput(&nativeEvent);

        // Dirty, evil hack to lock the cursor. SFML is working on a native cursor locking
        // feature beyond SFML 2.2, but for now we have to reset the cursor position manually.
        if (this->mouseInputMode == MouseInputMode::HIDE_AND_LOCK) 
        {
            sf::Mouse::setPosition(MOUSE_ORIGIN, *(this->window));
        }
    }
}

void InputView::onSfmlJoystickButtonPressed(sf::Event::JoystickButtonEvent event)
{
    // TODO: Joystick input
}

void InputView::onSfmlJoystickButtonReleased(sf::Event::JoystickButtonEvent event)
{
    // TODO: Joystick input
}

void InputView::onSfmlJoystickMoved(sf::Event::JoystickMoveEvent event)
{
    // TODO: Joystick input
}

void InputView::onSfmlJoystickConnected(sf::Event::JoystickConnectEvent event)
{
    // TODO: Joystick input
}

void InputView::onSfmlJoystickDisconnected(sf::Event::JoystickConnectEvent event)
{
    // TODO: Joystick input
}

void InputView::onSfmlTextEntered(sf::Event::TextEvent event)
{
    // TODO: Text entry
}

InputState InputView::GetKeyState(KeyboardKey keyCode)
{
    sf::Keyboard::Key sfmlKey = InputView::sfmlKeyboardKey(keyCode);
    if (sf::Keyboard::isKeyPressed(sfmlKey))
    {
        return InputState::PRESSED;
    } 
    else 
    {
        return InputState::RELEASED;
    }
}

InputState InputView::GetMouseButtonState(MouseButton button)
{
    if (sf::Mouse::isButtonPressed(InputView::sfmlMouseMacro(button)))
    {
        return InputState::PRESSED;
    }
    else
    {
        return InputState::RELEASED;
    }
}

int InputView::GetMouseAbsoluteX()
{
    sf::Vector2i position = sf::Mouse::getPosition();
    return position.x;
}

int InputView::GetMouseAbsoluteY()
{
    sf::Vector2i position = sf::Mouse::getPosition();
    return position.y;
}

KeyboardKey InputView::keyCode(sf::Keyboard::Key key)
{
    switch (key) {
        case sf::Keyboard::Key::A:
            return KeyboardKey::KEYBOARD_A;
        case sf::Keyboard::Key::B:
            return KeyboardKey::KEYBOARD_B;
        case sf::Keyboard::Key::C:
            return KeyboardKey::KEYBOARD_C;
        case sf::Keyboard::Key::D:
            return KeyboardKey::KEYBOARD_D;
        case sf::Keyboard::Key::E:
            return KeyboardKey::KEYBOARD_E;
        case sf::Keyboard::Key::F:
            return KeyboardKey::KEYBOARD_F;
        case sf::Keyboard::Key::G:
            return KeyboardKey::KEYBOARD_G;
        case sf::Keyboard::Key::H:
            return KeyboardKey::KEYBOARD_H;
        case sf::Keyboard::Key::I:
            return KeyboardKey::KEYBOARD_I;
        case sf::Keyboard::Key::J:
            return KeyboardKey::KEYBOARD_J;
        case sf::Keyboard::Key::K:
            return KeyboardKey::KEYBOARD_K;
        case sf::Keyboard::Key::L:
            return KeyboardKey::KEYBOARD_L;
        case sf::Keyboard::Key::M:
            return KeyboardKey::KEYBOARD_M;
        case sf::Keyboard::Key::N:
            return KeyboardKey::KEYBOARD_N;
        case sf::Keyboard::Key::O:
            return KeyboardKey::KEYBOARD_O;
        case sf::Keyboard::Key::P:
            return KeyboardKey::KEYBOARD_P;
        case sf::Keyboard::Key::Q:
            return KeyboardKey::KEYBOARD_Q;
        case sf::Keyboard::Key::R:
            return KeyboardKey::KEYBOARD_R;
        case sf::Keyboard::Key::S:
            return KeyboardKey::KEYBOARD_S;
        case sf::Keyboard::Key::T:
            return KeyboardKey::KEYBOARD_T;
        case sf::Keyboard::Key::U:
            return KeyboardKey::KEYBOARD_U;
        case sf::Keyboard::Key::V:
            return KeyboardKey::KEYBOARD_V;
        case sf::Keyboard::Key::W:
            return KeyboardKey::KEYBOARD_W;
        case sf::Keyboard::Key::X:
            return KeyboardKey::KEYBOARD_X;
        case sf::Keyboard::Key::Y:
            return KeyboardKey::KEYBOARD_Y;
        case sf::Keyboard::Key::Z:
            return KeyboardKey::KEYBOARD_Z;
        case sf::Keyboard::Key::Num1:
            return KeyboardKey::KEYBOARD_1;
        case sf::Keyboard::Key::Num2:
            return KeyboardKey::KEYBOARD_2;
        case sf::Keyboard::Key::Num3:
            return KeyboardKey::KEYBOARD_3;
        case sf::Keyboard::Key::Num4:
            return KeyboardKey::KEYBOARD_4;
        case sf::Keyboard::Key::Num5:
            return KeyboardKey::KEYBOARD_5;
        case sf::Keyboard::Key::Num6:
            return KeyboardKey::KEYBOARD_6;
        case sf::Keyboard::Key::Num7:
            return KeyboardKey::KEYBOARD_7;
        case sf::Keyboard::Key::Num8:
            return KeyboardKey::KEYBOARD_8;
        case sf::Keyboard::Key::Num9:
            return KeyboardKey::KEYBOARD_9;
        case sf::Keyboard::Key::Num0:
            return KeyboardKey::KEYBOARD_0;
        case sf::Keyboard::Key::Return:
            return KeyboardKey::KEYBOARD_ENTER;
        case sf::Keyboard::Key::Escape:
            return KeyboardKey::KEYBOARD_ESCAPE;
        case sf::Keyboard::Key::BackSpace:
            return KeyboardKey::KEYBOARD_BACKSPACE;
        case sf::Keyboard::Key::Tab:
            return KeyboardKey::KEYBOARD_TAB;
        case sf::Keyboard::Key::Space:
            return KeyboardKey::KEYBOARD_SPACEBAR;
        case sf::Keyboard::Key::Dash:
            return KeyboardKey::KEYBOARD_MINUS;
        case sf::Keyboard::Key::Equal:
            return KeyboardKey::KEYBOARD_EQUALS;
        case sf::Keyboard::Key::LBracket:
            return KeyboardKey::KEYBOARD_LEFT_BRACKET;
        case sf::Keyboard::Key::RBracket:
            return KeyboardKey::KEYBOARD_RIGHT_BRACKET;
        case sf::Keyboard::Key::BackSlash:
            return KeyboardKey::KEYBOARD_BACKSLASH;
        case sf::Keyboard::Key::SemiColon:
            return KeyboardKey::KEYBOARD_SEMICOLON;
        case sf::Keyboard::Key::Quote:
            return KeyboardKey::KEYBOARD_QUOTE;
        case sf::Keyboard::Key::Tilde:
            return KeyboardKey::KEYBOARD_GRAVE_ACCENT;
        case sf::Keyboard::Key::Comma:
            return KeyboardKey::KEYBOARD_COMMA;
        case sf::Keyboard::Key::Period:
            return KeyboardKey::KEYBOARD_PERIOD;
        case sf::Keyboard::Key::Slash:
            return KeyboardKey::KEYBOARD_FORWARD_SLASH;
        case sf::Keyboard::Key::F1:
            return KeyboardKey::KEYBOARD_F1;
        case sf::Keyboard::Key::F2:
            return KeyboardKey::KEYBOARD_F2;
        case sf::Keyboard::Key::F3:
            return KeyboardKey::KEYBOARD_F3;
        case sf::Keyboard::Key::F4:
            return KeyboardKey::KEYBOARD_F4;
        case sf::Keyboard::Key::F5:
            return KeyboardKey::KEYBOARD_F5;
        case sf::Keyboard::Key::F6:
            return KeyboardKey::KEYBOARD_F6;
        case sf::Keyboard::Key::F7:
            return KeyboardKey::KEYBOARD_F7;
        case sf::Keyboard::Key::F8:
            return KeyboardKey::KEYBOARD_F8;
        case sf::Keyboard::Key::F9:
            return KeyboardKey::KEYBOARD_F9;
        case sf::Keyboard::Key::F10:
            return KeyboardKey::KEYBOARD_F10;
        case sf::Keyboard::Key::F11:
            return KeyboardKey::KEYBOARD_F11;
        case sf::Keyboard::Key::F12:
            return KeyboardKey::KEYBOARD_F12;
        case sf::Keyboard::Key::Insert:
            return KeyboardKey::KEYBOARD_INSERT;
        case sf::Keyboard::Key::Home:
            return KeyboardKey::KEYBOARD_HOME;
        case sf::Keyboard::Key::PageUp:
            return KeyboardKey::KEYBOARD_PAGE_UP;
        case sf::Keyboard::Key::Delete:
            return KeyboardKey::KEYBOARD_DELETE;
        case sf::Keyboard::Key::End:
            return KeyboardKey::KEYBOARD_END;
        case sf::Keyboard::Key::PageDown:
            return KeyboardKey::KEYBOARD_PAGE_DOWN;
        case sf::Keyboard::Key::Right:
            return KeyboardKey::KEYBOARD_RIGHT_ARROW;
        case sf::Keyboard::Key::Left:
            return KeyboardKey::KEYBOARD_LEFT_ARROW;
        case sf::Keyboard::Key::Down:
            return KeyboardKey::KEYBOARD_DOWN_ARROW;
        case sf::Keyboard::Key::Up:
            return KeyboardKey::KEYBOARD_UP_ARROW;
        case sf::Keyboard::Key::Divide:
            return KeyboardKey::KEYBOARD_NUM_FORWARD_SLASH;
        case sf::Keyboard::Key::Multiply:
            return KeyboardKey::KEYBOARD_NUM_ASTERISK;
        case sf::Keyboard::Key::Subtract:
            return KeyboardKey::KEYBOARD_NUM_MINUS;
        case sf::Keyboard::Key::Add:
            return KeyboardKey::KEYBOARD_NUM_PLUS;
        case sf::Keyboard::Key::Numpad1:
            return KeyboardKey::KEYBOARD_NUM_1;
        case sf::Keyboard::Key::Numpad2:
            return KeyboardKey::KEYBOARD_NUM_2;
        case sf::Keyboard::Key::Numpad3:
            return KeyboardKey::KEYBOARD_NUM_3;
        case sf::Keyboard::Key::Numpad4:
            return KeyboardKey::KEYBOARD_NUM_3;
        case sf::Keyboard::Key::Numpad5:
            return KeyboardKey::KEYBOARD_NUM_5;
        case sf::Keyboard::Key::Numpad6:
            return KeyboardKey::KEYBOARD_NUM_6;
        case sf::Keyboard::Key::Numpad7:
            return KeyboardKey::KEYBOARD_NUM_7;
        case sf::Keyboard::Key::Numpad8:
            return KeyboardKey::KEYBOARD_NUM_8;
        case sf::Keyboard::Key::Numpad9:
            return KeyboardKey::KEYBOARD_NUM_9;
        case sf::Keyboard::Key::Numpad0:
            return KeyboardKey::KEYBOARD_NUM_0;
        case sf::Keyboard::Key::LControl:
            return KeyboardKey::KEYBOARD_LEFT_CONTROL;
        case sf::Keyboard::Key::LShift:
            return KeyboardKey::KEYBOARD_LEFT_SHIFT;
        case sf::Keyboard::Key::LAlt:
            return KeyboardKey::KEYBOARD_LEFT_ALT;
        case sf::Keyboard::Key::LSystem:
            return KeyboardKey::KEYBOARD_LEFT_SUPER;
        case sf::Keyboard::Key::RControl:
            return KeyboardKey::KEYBOARD_RIGHT_CONTROL;
        case sf::Keyboard::Key::RShift:
            return KeyboardKey::KEYBOARD_RIGHT_SHIFT;
        case sf::Keyboard::Key::RAlt:
            return KeyboardKey::KEYBOARD_RIGHT_ALT;
        case sf::Keyboard::Key::RSystem:
            return KeyboardKey::KEYBOARD_RIGHT_SUPER;
        case sf::Keyboard::Key::Unknown:
            return KeyboardKey::KEYBOARD_UNKNOWN;
        default:
            return KeyboardKey::KEYBOARD_UNKNOWN;
    }
}

sf::Keyboard::Key InputView::sfmlKeyboardKey(KeyboardKey key) 
{
    switch (key) {
        case KeyboardKey::KEYBOARD_A:
            return sf::Keyboard::Key::A;
        case KeyboardKey::KEYBOARD_B:
            return sf::Keyboard::Key::B;
        case KeyboardKey::KEYBOARD_C:
            return sf::Keyboard::Key::C;
        case KeyboardKey::KEYBOARD_D:
            return sf::Keyboard::Key::D;
        case KeyboardKey::KEYBOARD_E:
            return sf::Keyboard::Key::E;
        case KeyboardKey::KEYBOARD_F:
            return sf::Keyboard::Key::F;
        case KeyboardKey::KEYBOARD_G:
            return sf::Keyboard::Key::G;
        case KeyboardKey::KEYBOARD_H:
            return sf::Keyboard::Key::H;
        case KeyboardKey::KEYBOARD_I:
            return sf::Keyboard::Key::I;
        case KeyboardKey::KEYBOARD_J:
            return sf::Keyboard::Key::J;
        case KeyboardKey::KEYBOARD_K:
            return sf::Keyboard::Key::K;
        case KeyboardKey::KEYBOARD_L:
            return sf::Keyboard::Key::L;
        case KeyboardKey::KEYBOARD_M:
            return sf::Keyboard::Key::M;
        case KeyboardKey::KEYBOARD_N:
            return sf::Keyboard::Key::N;
        case KeyboardKey::KEYBOARD_O:
            return sf::Keyboard::Key::O;
        case KeyboardKey::KEYBOARD_P:
            return sf::Keyboard::Key::P;
        case KeyboardKey::KEYBOARD_Q:
            return sf::Keyboard::Key::Q;
        case KeyboardKey::KEYBOARD_R:
            return sf::Keyboard::Key::R;
        case KeyboardKey::KEYBOARD_S:
            return sf::Keyboard::Key::S;
        case KeyboardKey::KEYBOARD_T:
            return sf::Keyboard::Key::T;
        case KeyboardKey::KEYBOARD_U:
            return sf::Keyboard::Key::U;
        case KeyboardKey::KEYBOARD_V:
            return sf::Keyboard::Key::V;
        case KeyboardKey::KEYBOARD_W:
            return sf::Keyboard::Key::W;
        case KeyboardKey::KEYBOARD_X:
            return sf::Keyboard::Key::X;
        case KeyboardKey::KEYBOARD_Y:
            return sf::Keyboard::Key::Y;
        case KeyboardKey::KEYBOARD_Z:
            return sf::Keyboard::Key::Z;
        case KeyboardKey::KEYBOARD_1:
            return sf::Keyboard::Key::Num1;
        case KeyboardKey::KEYBOARD_2:
            return sf::Keyboard::Key::Num2;
        case KeyboardKey::KEYBOARD_3:
            return sf::Keyboard::Key::Num3;
        case KeyboardKey::KEYBOARD_4:
            return sf::Keyboard::Key::Num4;
        case KeyboardKey::KEYBOARD_5:
            return sf::Keyboard::Key::Num5;
        case KeyboardKey::KEYBOARD_6:
            return sf::Keyboard::Key::Num6;
        case KeyboardKey::KEYBOARD_7:
            return sf::Keyboard::Key::Num7;
        case KeyboardKey::KEYBOARD_8:
            return sf::Keyboard::Key::Num8;
        case KeyboardKey::KEYBOARD_9:
            return sf::Keyboard::Key::Num9;
        case KeyboardKey::KEYBOARD_0:
            return sf::Keyboard::Key::Num0;
        case KeyboardKey::KEYBOARD_ENTER:
            return sf::Keyboard::Key::Return;
        case KeyboardKey::KEYBOARD_ESCAPE:
            return sf::Keyboard::Key::Escape;
        case KeyboardKey::KEYBOARD_BACKSPACE:
            return sf::Keyboard::Key::BackSpace;
        case KeyboardKey::KEYBOARD_TAB:
            return sf::Keyboard::Key::Tab;
        case KeyboardKey::KEYBOARD_SPACEBAR:
            return sf::Keyboard::Key::Space;
        case KeyboardKey::KEYBOARD_MINUS:
            return sf::Keyboard::Key::Dash;
        case KeyboardKey::KEYBOARD_EQUALS:
            return sf::Keyboard::Key::Equal;
        case KeyboardKey::KEYBOARD_LEFT_BRACKET:
            return sf::Keyboard::Key::LBracket;
        case KeyboardKey::KEYBOARD_RIGHT_BRACKET:
            return sf::Keyboard::Key::RBracket;
        case KeyboardKey::KEYBOARD_BACKSLASH:
            return sf::Keyboard::Key::BackSlash;
        case KeyboardKey::KEYBOARD_SEMICOLON:
            return sf::Keyboard::Key::SemiColon;
        case KeyboardKey::KEYBOARD_QUOTE:
            return sf::Keyboard::Key::Quote;
        case KeyboardKey::KEYBOARD_GRAVE_ACCENT:
            return sf::Keyboard::Key::Tilde;
        case KeyboardKey::KEYBOARD_COMMA:
            return sf::Keyboard::Key::Comma;
        case KeyboardKey::KEYBOARD_PERIOD:
            return sf::Keyboard::Key::Period;
        case KeyboardKey::KEYBOARD_FORWARD_SLASH:
            return sf::Keyboard::Key::Slash;
        case KeyboardKey::KEYBOARD_F1:
            return sf::Keyboard::Key::F1;
        case KeyboardKey::KEYBOARD_F2:
            return sf::Keyboard::Key::F2;
        case KeyboardKey::KEYBOARD_F3:
            return sf::Keyboard::Key::F3;
        case KeyboardKey::KEYBOARD_F4:
            return sf::Keyboard::Key::F4;
        case KeyboardKey::KEYBOARD_F5:
            return sf::Keyboard::Key::F5;
        case KeyboardKey::KEYBOARD_F6:
            return sf::Keyboard::Key::F6;
        case KeyboardKey::KEYBOARD_F7:
            return sf::Keyboard::Key::F7;
        case KeyboardKey::KEYBOARD_F8:
            return sf::Keyboard::Key::F8;
        case KeyboardKey::KEYBOARD_F9:
            return sf::Keyboard::Key::F9;
        case KeyboardKey::KEYBOARD_F10:
            return sf::Keyboard::Key::F10;
        case KeyboardKey::KEYBOARD_F11:
            return sf::Keyboard::Key::F11;
        case KeyboardKey::KEYBOARD_F12:
            return sf::Keyboard::Key::F12;
        case KeyboardKey::KEYBOARD_INSERT:
            return sf::Keyboard::Key::Insert;
        case KeyboardKey::KEYBOARD_HOME:
            return sf::Keyboard::Key::Home;
        case KeyboardKey::KEYBOARD_PAGE_UP:
            return sf::Keyboard::Key::PageUp;
        case KeyboardKey::KEYBOARD_DELETE:
            return sf::Keyboard::Key::Delete;
        case KeyboardKey::KEYBOARD_END:
            return sf::Keyboard::Key::End;
        case KeyboardKey::KEYBOARD_PAGE_DOWN:
            return sf::Keyboard::Key::PageDown;
        case KeyboardKey::KEYBOARD_RIGHT_ARROW:
            return sf::Keyboard::Key::Right;
        case KeyboardKey::KEYBOARD_LEFT_ARROW:
            return sf::Keyboard::Key::Left;
        case KeyboardKey::KEYBOARD_DOWN_ARROW:
            return sf::Keyboard::Key::Down;
        case KeyboardKey::KEYBOARD_UP_ARROW:
            return sf::Keyboard::Key::Up;
        case KeyboardKey::KEYBOARD_NUM_FORWARD_SLASH:
            return sf::Keyboard::Key::Divide;
        case KeyboardKey::KEYBOARD_NUM_ASTERISK:
            return sf::Keyboard::Key::Multiply;
        case KeyboardKey::KEYBOARD_NUM_MINUS:
            return sf::Keyboard::Key::Subtract;
        case KeyboardKey::KEYBOARD_NUM_PLUS:
            return sf::Keyboard::Key::Add;
        case KeyboardKey::KEYBOARD_NUM_1:
            return sf::Keyboard::Key::Numpad1;
        case KeyboardKey::KEYBOARD_NUM_2:
            return sf::Keyboard::Key::Numpad2;
        case KeyboardKey::KEYBOARD_NUM_3:
            return sf::Keyboard::Key::Numpad3;
        case KeyboardKey::KEYBOARD_NUM_4:
            return sf::Keyboard::Key::Numpad4;
        case KeyboardKey::KEYBOARD_NUM_5:
            return sf::Keyboard::Key::Numpad5;
        case KeyboardKey::KEYBOARD_NUM_6:
            return sf::Keyboard::Key::Numpad6;
        case KeyboardKey::KEYBOARD_NUM_7:
            return sf::Keyboard::Key::Numpad7;
        case KeyboardKey::KEYBOARD_NUM_8:
            return sf::Keyboard::Key::Numpad8;
        case KeyboardKey::KEYBOARD_NUM_9:
            return sf::Keyboard::Key::Numpad9;
        case KeyboardKey::KEYBOARD_NUM_0:
            return sf::Keyboard::Key::Numpad0;
        case KeyboardKey::KEYBOARD_LEFT_CONTROL:
            return sf::Keyboard::Key::LControl;
        case KeyboardKey::KEYBOARD_LEFT_SHIFT:
            return sf::Keyboard::Key::LShift;
        case KeyboardKey::KEYBOARD_LEFT_ALT:
            return sf::Keyboard::Key::LAlt;
        case KeyboardKey::KEYBOARD_LEFT_SUPER:
            return sf::Keyboard::Key::LSystem;
        case KeyboardKey::KEYBOARD_RIGHT_CONTROL:
            return sf::Keyboard::Key::RControl;
        case KeyboardKey::KEYBOARD_RIGHT_SHIFT:
            return sf::Keyboard::Key::RShift;
        case KeyboardKey::KEYBOARD_RIGHT_ALT:
            return sf::Keyboard::Key::RAlt;
        case KeyboardKey::KEYBOARD_RIGHT_SUPER:
            return sf::Keyboard::Key::RSystem;
        default:
            //undefined behavior
            assert(false);
    }
}

MouseButton InputView::mouseCode(sf::Mouse::Button button)
{
    switch(button)
    {
        case sf::Mouse::Left:
            return MouseButton::MOUSE_1;
        case sf::Mouse::Right:
            return MouseButton::MOUSE_2;
        case sf::Mouse::Middle:
            return MouseButton::MOUSE_3;
        case sf::Mouse::XButton1:
            return MouseButton::MOUSE_4;
        case sf::Mouse::XButton2:
            return MouseButton::MOUSE_5;
        default:
            // undefined behavior
            assert(false);
    }
}

sf::Mouse::Button InputView::sfmlMouseMacro(MouseButton button)
{
    switch(button)
    {
        case MouseButton::MOUSE_1:
            return sf::Mouse::Left;
        case MouseButton::MOUSE_2:
            return sf::Mouse::Right;
        case MouseButton::MOUSE_3:
            return sf::Mouse::Middle;
        case MouseButton::MOUSE_4:
            return sf::Mouse::XButton1;
        case MouseButton::MOUSE_5:
            return sf::Mouse::XButton2;
        default:
            // undefined behavior
            assert(false);
    }
}
