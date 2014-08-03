#include "InputView.h"
#include "GLFW/glfw3.h"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"
#include "KeyPressEvent.h"
#include "KeyReleaseEvent.h"
#include "MouseEvent.h"
#include "MouseButtonPressEvent.h"
#include "MouseButtonReleaseEvent.h"
#include "assert.h"
#include "set"
#include "vector"

InputView::InputView(sf::Window* window)
{
    this->window = window;
    this->inputManager = nullptr;
}

void InputView::Initialize()
{
}

void InputView::Update(InputManager* inputManager)
{
	this->inputManager = inputManager;
}

void InputView::OnSfmlEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed){
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
    assert(inputManager != nullptr);
    KeyCode keyCode = InputView::keyCode(event.code);
    if (inputManager->IsRegisteredEventHandler(&keyCode))
    {
        KeyPressEvent nativeEvent(&keyCode);
        inputManager->OnKeyboardKeyPress(&nativeEvent);
    }
}

void InputView::onSfmlKeyReleased(sf::Event::KeyEvent event)
{
    assert(inputManager != nullptr);
    KeyCode keyCode = InputView::keyCode(event.code);
    if (inputManager->IsRegisteredEventHandler(&keyCode))
    {
        KeyReleaseEvent event(&keyCode);
        inputManager->OnKeyboardKeyRelease(&event);
    }
}

void InputView::onSfmlMouseWheelMoved(sf::Event::MouseWheelEvent event)
{
    // TODO: mouse wheel input handling
}

void InputView::onSfmlMouseButtonPressed(sf::Event::MouseButtonEvent event)
{
    assert(inputManager != nullptr);
    MouseCode mouseCode = InputView::mouseCode(event.button);
    MouseButtonPressEvent nativeEvent(event.x, event.y, mouseCode);
    inputManager->OnMouseButtonPress(&nativeEvent);
}

void InputView::onSfmlMouseButtonReleased(sf::Event::MouseButtonEvent event)
{
    assert(inputManager != nullptr);
    MouseCode mouseCode = InputView::mouseCode(event.button);
    MouseButtonReleaseEvent nativeEvent(event.x, event.y, mouseCode);
    inputManager->OnMouseButtonRelease(&nativeEvent);
}

void InputView::onSfmlMouseMoved(sf::Event::MouseMoveEvent event)
{
    assert(inputManager != nullptr);
    MouseEvent nativeEvent(event.x, event.y);
    inputManager->OnMouseInput(&nativeEvent);
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

InputState InputView::GetKeyState(KeyCode keyCode)
{
    sf::Keyboard::Key sfmlKey = InputView::sfmlKeyCode(keyCode);
    if (sf::Keyboard::isKeyPressed(sfmlKey))
    {
        return InputState::PRESSED;
    } 
    else 
    {
        return InputState::RELEASED;
    }
}

InputState InputView::GetMouseButtonState(MouseCode mouseCode)
{
    sf::Mouse::Button sfmlButton = InputView::sfmlMouseMacro(mouseCode);
    if (sf::Mouse::isButtonPressed(sfmlButton))
    {
        return InputState::PRESSED;
    }
    else
    {
        return InputState::PRESSED;
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

KeyCode InputView::keyCode(sf::Keyboard::Key sfmlKey)
{
	switch (sfmlKey) {
		case sf::Keyboard::Key::A:
		    return KeyCode::KEYBOARD_A;
		case sf::Keyboard::Key::B:
		    return KeyCode::KEYBOARD_B;
		case sf::Keyboard::Key::C:
		    return KeyCode::KEYBOARD_C;
		case sf::Keyboard::Key::D:
		    return KeyCode::KEYBOARD_D;
		case sf::Keyboard::Key::E:
		    return KeyCode::KEYBOARD_E;
		case sf::Keyboard::Key::F:
		    return KeyCode::KEYBOARD_F;
		case sf::Keyboard::Key::G:
		    return KeyCode::KEYBOARD_G;
		case sf::Keyboard::Key::H:
		    return KeyCode::KEYBOARD_H;
		case sf::Keyboard::Key::I:
	    	return KeyCode::KEYBOARD_I;
		case sf::Keyboard::Key::J:
	    	return KeyCode::KEYBOARD_J;
		case sf::Keyboard::Key::K:
	    	return KeyCode::KEYBOARD_K;
		case sf::Keyboard::Key::L:
	    	return KeyCode::KEYBOARD_L;
		case sf::Keyboard::Key::M:
	    	return KeyCode::KEYBOARD_M;
		case sf::Keyboard::Key::N:
	    	return KeyCode::KEYBOARD_N;
		case sf::Keyboard::Key::O:
	    	return KeyCode::KEYBOARD_O;
		case sf::Keyboard::Key::P:
	    	return KeyCode::KEYBOARD_P;
		case sf::Keyboard::Key::Q:
	    	return KeyCode::KEYBOARD_Q;
		case sf::Keyboard::Key::R:
	    	return KeyCode::KEYBOARD_R;
		case sf::Keyboard::Key::S:
	    	return KeyCode::KEYBOARD_S;
		case sf::Keyboard::Key::T:
	    	return KeyCode::KEYBOARD_T;
		case sf::Keyboard::Key::U:
	    	return KeyCode::KEYBOARD_U;
		case sf::Keyboard::Key::V:
	    	return KeyCode::KEYBOARD_V;
		case sf::Keyboard::Key::W:
	    	return KeyCode::KEYBOARD_W;
		case sf::Keyboard::Key::X:
	    	return KeyCode::KEYBOARD_X;
		case sf::Keyboard::Key::Y:
	    	return KeyCode::KEYBOARD_Y;
		case sf::Keyboard::Key::Z:
	    	return KeyCode::KEYBOARD_Z;
		case sf::Keyboard::Key::Num1:
	    	return KeyCode::KEYBOARD_1;
		case sf::Keyboard::Key::Num2:
	    	return KeyCode::KEYBOARD_2;
		case sf::Keyboard::Key::Num3:
	    	return KeyCode::KEYBOARD_3;
		case sf::Keyboard::Key::Num4:
	    	return KeyCode::KEYBOARD_4;
		case sf::Keyboard::Key::Num5:
	    	return KeyCode::KEYBOARD_5;
		case sf::Keyboard::Key::Num6:
	    	return KeyCode::KEYBOARD_6;
		case sf::Keyboard::Key::Num7:
	    	return KeyCode::KEYBOARD_7;
		case sf::Keyboard::Key::Num8:
	    	return KeyCode::KEYBOARD_8;
		case sf::Keyboard::Key::Num9:
	    	return KeyCode::KEYBOARD_9;
		case sf::Keyboard::Key::Num0:
	    	return KeyCode::KEYBOARD_0;
        case sf::Keyboard::Key::Return:
	    	return KeyCode::KEYBOARD_ENTER;
		case sf::Keyboard::Key::Escape:
	    	return KeyCode::KEYBOARD_ESCAPE;
		case sf::Keyboard::Key::BackSpace:
	    	return KeyCode::KEYBOARD_BACKSPACE;
		case sf::Keyboard::Key::Tab:
	    	return KeyCode::KEYBOARD_TAB;
		case sf::Keyboard::Key::Space:
		    return KeyCode::KEYBOARD_SPACEBAR;
		case sf::Keyboard::Key::Dash:
    		return KeyCode::KEYBOARD_MINUS;
		case sf::Keyboard::Key::Equal:
	    	return KeyCode::KEYBOARD_EQUALS;
		case sf::Keyboard::Key::LBracket:
	    	return KeyCode::KEYBOARD_LEFT_BRACKET;
		case sf::Keyboard::Key::RBracket:
	    	return KeyCode::KEYBOARD_RIGHT_BRACKET;
		case sf::Keyboard::Key::BackSlash:
    		return KeyCode::KEYBOARD_BACKSLASH;
		case sf::Keyboard::Key::SemiColon:
    		return KeyCode::KEYBOARD_SEMICOLON;
		case sf::Keyboard::Key::Quote:
    		return KeyCode::KEYBOARD_QUOTE;
		case sf::Keyboard::Key::Tilde:
    		return KeyCode::KEYBOARD_GRAVE_ACCENT;
		case sf::Keyboard::Key::Comma:
    		return KeyCode::KEYBOARD_COMMA;
		case sf::Keyboard::Key::Period:
    		return KeyCode::KEYBOARD_PERIOD;
		case sf::Keyboard::Key::Slash:
    		return KeyCode::KEYBOARD_FORWARD_SLASH;
		case sf::Keyboard::Key::F1:
    		return KeyCode::KEYBOARD_F1;
		case sf::Keyboard::Key::F2:
	    	return KeyCode::KEYBOARD_F2;
		case sf::Keyboard::Key::F3:
    		return KeyCode::KEYBOARD_F3;
		case sf::Keyboard::Key::F4:
	    	return KeyCode::KEYBOARD_F4;
		case sf::Keyboard::Key::F5:
	    	return KeyCode::KEYBOARD_F5;
		case sf::Keyboard::Key::F6:
	    	return KeyCode::KEYBOARD_F6;
		case sf::Keyboard::Key::F7:
	    	return KeyCode::KEYBOARD_F7;
		case sf::Keyboard::Key::F8:
	    	return KeyCode::KEYBOARD_F8;
		case sf::Keyboard::Key::F9:
	    	return KeyCode::KEYBOARD_F9;
		case sf::Keyboard::Key::F10:
	    	return KeyCode::KEYBOARD_F10;
		case sf::Keyboard::Key::F11:
    		return KeyCode::KEYBOARD_F11;
		case sf::Keyboard::Key::F12:
    		return KeyCode::KEYBOARD_F12;
		case sf::Keyboard::Key::Insert:
    		return KeyCode::KEYBOARD_INSERT;
		case sf::Keyboard::Key::Home:
    		return KeyCode::KEYBOARD_HOME;
		case sf::Keyboard::Key::PageUp:
	    	return KeyCode::KEYBOARD_PAGE_UP;
		case sf::Keyboard::Key::Delete:
	    	return KeyCode::KEYBOARD_DELETE;
		case sf::Keyboard::Key::End:
    		return KeyCode::KEYBOARD_END;
		case sf::Keyboard::Key::PageDown:
    		return KeyCode::KEYBOARD_PAGE_DOWN;
		case sf::Keyboard::Key::Right:
    		return KeyCode::KEYBOARD_RIGHT_ARROW;
		case sf::Keyboard::Key::Left:
    		return KeyCode::KEYBOARD_LEFT_ARROW;
		case sf::Keyboard::Key::Down:
    		return KeyCode::KEYBOARD_DOWN_ARROW;
		case sf::Keyboard::Key::Up:
    		return KeyCode::KEYBOARD_UP_ARROW;
		case sf::Keyboard::Key::Divide:
    		return KeyCode::KEYBOARD_NUM_FORWARD_SLASH;
		case sf::Keyboard::Key::Multiply:
	    	return KeyCode::KEYBOARD_NUM_ASTERISK;
    	case sf::Keyboard::Key::Subtract:
    		return KeyCode::KEYBOARD_NUM_MINUS;
		case sf::Keyboard::Key::Add:
    		return KeyCode::KEYBOARD_NUM_PLUS;
		case sf::Keyboard::Key::Numpad1:
    		return KeyCode::KEYBOARD_NUM_1;
		case sf::Keyboard::Key::Numpad2:
    		return KeyCode::KEYBOARD_NUM_2;
		case sf::Keyboard::Key::Numpad3:
    		return KeyCode::KEYBOARD_NUM_3;
		case sf::Keyboard::Key::Numpad4:
    		return KeyCode::KEYBOARD_NUM_3;
		case sf::Keyboard::Key::Numpad5:
    		return KeyCode::KEYBOARD_NUM_5;
		case sf::Keyboard::Key::Numpad6:
	    	return KeyCode::KEYBOARD_NUM_6;
    	case sf::Keyboard::Key::Numpad7:
	    	return KeyCode::KEYBOARD_NUM_7;
		case sf::Keyboard::Key::Numpad8:
	    	return KeyCode::KEYBOARD_NUM_8;
		case sf::Keyboard::Key::Numpad9:
	    	return KeyCode::KEYBOARD_NUM_9;
		case sf::Keyboard::Key::Numpad0:
            return KeyCode::KEYBOARD_NUM_0;
		case sf::Keyboard::Key::LControl:
	    	return KeyCode::KEYBOARD_LEFT_CONTROL;
		case sf::Keyboard::Key::LShift:
	    	return KeyCode::KEYBOARD_LEFT_SHIFT;
		case sf::Keyboard::Key::LAlt:
	    	return KeyCode::KEYBOARD_LEFT_ALT;
		case sf::Keyboard::Key::LSystem:
	    	return KeyCode::KEYBOARD_LEFT_SUPER;
		case sf::Keyboard::Key::RControl:
	    	return KeyCode::KEYBOARD_RIGHT_CONTROL;
		case sf::Keyboard::Key::RShift:
	    	return KeyCode::KEYBOARD_RIGHT_SHIFT;
		case sf::Keyboard::Key::RAlt:
	    	return KeyCode::KEYBOARD_RIGHT_ALT;
		case sf::Keyboard::Key::RSystem:
	    	return KeyCode::KEYBOARD_RIGHT_SUPER;
		case sf::Keyboard::Key::Unknown:
	    	return KeyCode::KEYBOARD_UNKNOWN;
		default:
	    	return KeyCode::KEYBOARD_UNKNOWN;
	}
}

sf::Keyboard::Key InputView::sfmlKeyCode(KeyCode keyCode) 
{
	switch (keyCode) {
		case KeyCode::KEYBOARD_A:
    		return sf::Keyboard::Key::A;
		case KeyCode::KEYBOARD_B:
    		return sf::Keyboard::Key::B;
		case KeyCode::KEYBOARD_C:
    		return sf::Keyboard::Key::C;
		case KeyCode::KEYBOARD_D:
	    	return sf::Keyboard::Key::D;
		case KeyCode::KEYBOARD_E:
	    	return sf::Keyboard::Key::E;
		case KeyCode::KEYBOARD_F:
	    	return sf::Keyboard::Key::F;
		case KeyCode::KEYBOARD_G:
	    	return sf::Keyboard::Key::G;
		case KeyCode::KEYBOARD_H:
	    	return sf::Keyboard::Key::H;
		case KeyCode::KEYBOARD_I:
    		return sf::Keyboard::Key::I;
		case KeyCode::KEYBOARD_J:
    		return sf::Keyboard::Key::J;
		case KeyCode::KEYBOARD_K:
    		return sf::Keyboard::Key::K;
		case KeyCode::KEYBOARD_L:
    		return sf::Keyboard::Key::L;
		case KeyCode::KEYBOARD_M:
    		return sf::Keyboard::Key::M;
		case KeyCode::KEYBOARD_N:
	    	return sf::Keyboard::Key::N;
		case KeyCode::KEYBOARD_O:
    		return sf::Keyboard::Key::O;
		case KeyCode::KEYBOARD_P:
    		return sf::Keyboard::Key::P;
		case KeyCode::KEYBOARD_Q:
    		return sf::Keyboard::Key::Q;
		case KeyCode::KEYBOARD_R:
    		return sf::Keyboard::Key::R;
		case KeyCode::KEYBOARD_S:
    		return sf::Keyboard::Key::S;
		case KeyCode::KEYBOARD_T:
    		return sf::Keyboard::Key::T;
		case KeyCode::KEYBOARD_U:
    		return sf::Keyboard::Key::U;
		case KeyCode::KEYBOARD_V:
    		return sf::Keyboard::Key::V;
		case KeyCode::KEYBOARD_W:
    		return sf::Keyboard::Key::W;
		case KeyCode::KEYBOARD_X:
    		return sf::Keyboard::Key::X;
   		case KeyCode::KEYBOARD_Y:
    		return sf::Keyboard::Key::Y;
   		case KeyCode::KEYBOARD_Z:
		    return sf::Keyboard::Key::Z;
		case KeyCode::KEYBOARD_1:
	    	return sf::Keyboard::Key::Num1;
		case KeyCode::KEYBOARD_2:
	    	return sf::Keyboard::Key::Num2;
		case KeyCode::KEYBOARD_3:
	    	return sf::Keyboard::Key::Num3;
		case KeyCode::KEYBOARD_4:
	    	return sf::Keyboard::Key::Num4;
		case KeyCode::KEYBOARD_5:
	    	return sf::Keyboard::Key::Num5;
		case KeyCode::KEYBOARD_6:
	    	return sf::Keyboard::Key::Num6;
		case KeyCode::KEYBOARD_7:
	    	return sf::Keyboard::Key::Num7;
		case KeyCode::KEYBOARD_8:
	    	return sf::Keyboard::Key::Num8;
		case KeyCode::KEYBOARD_9:
	    	return sf::Keyboard::Key::Num9;
		case KeyCode::KEYBOARD_0:
	    	return sf::Keyboard::Key::Num0;
		case KeyCode::KEYBOARD_ENTER:
	    	return sf::Keyboard::Key::Return;
		case KeyCode::KEYBOARD_ESCAPE:
	    	return sf::Keyboard::Key::Escape;
		case KeyCode::KEYBOARD_BACKSPACE:
	    	return sf::Keyboard::Key::BackSpace;
		case KeyCode::KEYBOARD_TAB:
	    	return sf::Keyboard::Key::Tab;
		case KeyCode::KEYBOARD_SPACEBAR:
	    	return sf::Keyboard::Key::Space;
		case KeyCode::KEYBOARD_MINUS:
	    	return sf::Keyboard::Key::Dash;
		case KeyCode::KEYBOARD_EQUALS:
	    	return sf::Keyboard::Key::Equal;
		case KeyCode::KEYBOARD_LEFT_BRACKET:
	    	return sf::Keyboard::Key::LBracket;
		case KeyCode::KEYBOARD_RIGHT_BRACKET:
	    	return sf::Keyboard::Key::RBracket;
		case KeyCode::KEYBOARD_BACKSLASH:
	    	return sf::Keyboard::Key::BackSlash;
		case KeyCode::KEYBOARD_SEMICOLON:
	    	return sf::Keyboard::Key::SemiColon;
		case KeyCode::KEYBOARD_QUOTE:
	    	return sf::Keyboard::Key::Quote;
		case KeyCode::KEYBOARD_GRAVE_ACCENT:
	    	return sf::Keyboard::Key::Tilde;
		case KeyCode::KEYBOARD_COMMA:
	    	return sf::Keyboard::Key::Comma;
		case KeyCode::KEYBOARD_PERIOD:
	    	return sf::Keyboard::Key::Period;
		case KeyCode::KEYBOARD_FORWARD_SLASH:
	    	return sf::Keyboard::Key::Slash;
		case KeyCode::KEYBOARD_F1:
	    	return sf::Keyboard::Key::F1;
		case KeyCode::KEYBOARD_F2:
	    	return sf::Keyboard::Key::F2;
		case KeyCode::KEYBOARD_F3:
	    	return sf::Keyboard::Key::F3;
		case KeyCode::KEYBOARD_F4:
	    	return sf::Keyboard::Key::F4;
		case KeyCode::KEYBOARD_F5:
	    	return sf::Keyboard::Key::F5;
		case KeyCode::KEYBOARD_F6:
	    	return sf::Keyboard::Key::F6;
		case KeyCode::KEYBOARD_F7:
	    	return sf::Keyboard::Key::F7;
		case KeyCode::KEYBOARD_F8:
	    	return sf::Keyboard::Key::F8;
		case KeyCode::KEYBOARD_F9:
	    	return sf::Keyboard::Key::F9;
		case KeyCode::KEYBOARD_F10:
	    	return sf::Keyboard::Key::F10;
		case KeyCode::KEYBOARD_F11:
	    	return sf::Keyboard::Key::F11;
		case KeyCode::KEYBOARD_F12:
	    	return sf::Keyboard::Key::F12;
		case KeyCode::KEYBOARD_INSERT:
	    	return sf::Keyboard::Key::Insert;
		case KeyCode::KEYBOARD_HOME:
	    	return sf::Keyboard::Key::Home;
		case KeyCode::KEYBOARD_PAGE_UP:
	    	return sf::Keyboard::Key::PageUp;
		case KeyCode::KEYBOARD_DELETE:
	    	return sf::Keyboard::Key::Delete;
		case KeyCode::KEYBOARD_END:
	    	return sf::Keyboard::Key::End;
		case KeyCode::KEYBOARD_PAGE_DOWN:
	    	return sf::Keyboard::Key::PageDown;
		case KeyCode::KEYBOARD_RIGHT_ARROW:
	    	return sf::Keyboard::Key::Right;
		case KeyCode::KEYBOARD_LEFT_ARROW:
	    	return sf::Keyboard::Key::Left;
		case KeyCode::KEYBOARD_DOWN_ARROW:
	    	return sf::Keyboard::Key::Down;
		case KeyCode::KEYBOARD_UP_ARROW:
	    	return sf::Keyboard::Key::Up;
		case KeyCode::KEYBOARD_NUM_FORWARD_SLASH:
	    	return sf::Keyboard::Key::Divide;
		case KeyCode::KEYBOARD_NUM_ASTERISK:
	    	return sf::Keyboard::Key::Multiply;
		case KeyCode::KEYBOARD_NUM_MINUS:
	    	return sf::Keyboard::Key::Subtract;
		case KeyCode::KEYBOARD_NUM_PLUS:
	    	return sf::Keyboard::Key::Add;
		case KeyCode::KEYBOARD_NUM_1:
	    	return sf::Keyboard::Key::Numpad1;
		case KeyCode::KEYBOARD_NUM_2:
	    	return sf::Keyboard::Key::Numpad2;
		case KeyCode::KEYBOARD_NUM_3:
	    	return sf::Keyboard::Key::Numpad3;
		case KeyCode::KEYBOARD_NUM_4:
	    	return sf::Keyboard::Key::Numpad4;
		case KeyCode::KEYBOARD_NUM_5:
	    	return sf::Keyboard::Key::Numpad5;
		case KeyCode::KEYBOARD_NUM_6:
	    	return sf::Keyboard::Key::Numpad6;
		case KeyCode::KEYBOARD_NUM_7:
	    	return sf::Keyboard::Key::Numpad7;
		case KeyCode::KEYBOARD_NUM_8:
	       	return sf::Keyboard::Key::Numpad8;
		case KeyCode::KEYBOARD_NUM_9:
	     	return sf::Keyboard::Key::Numpad9;
		case KeyCode::KEYBOARD_NUM_0:
	     	return sf::Keyboard::Key::Numpad0;
		case KeyCode::KEYBOARD_LEFT_CONTROL:
	     	return sf::Keyboard::Key::LControl;
		case KeyCode::KEYBOARD_LEFT_SHIFT:
	     	return sf::Keyboard::Key::LShift;
		case KeyCode::KEYBOARD_LEFT_ALT:
	     	return sf::Keyboard::Key::LAlt;
		case KeyCode::KEYBOARD_LEFT_SUPER:
	     	return sf::Keyboard::Key::LSystem;
		case KeyCode::KEYBOARD_RIGHT_CONTROL:
	     	return sf::Keyboard::Key::RControl;
		case KeyCode::KEYBOARD_RIGHT_SHIFT:
	     	return sf::Keyboard::Key::RShift;
		case KeyCode::KEYBOARD_RIGHT_ALT:
	     	return sf::Keyboard::Key::RAlt;
		case KeyCode::KEYBOARD_RIGHT_SUPER:
	     	return sf::Keyboard::Key::RSystem;
		default:
            //undefined behavior
            assert(false);
	}
}

MouseCode InputView::mouseCode(sf::Mouse::Button sfmlMouseButton)
{
    switch(sfmlMouseButton)
    {
        case sf::Mouse::Left:
            return MouseCode::MOUSE_1;
        case sf::Mouse::Right:
            return MouseCode::MOUSE_2;
        case sf::Mouse::Middle:
            return MouseCode::MOUSE_3;
        case sf::Mouse::XButton1:
            return MouseCode::MOUSE_4;
        case sf::Mouse::XButton2:
            return MouseCode::MOUSE_5;
        default:
            // undefined behavior
            assert(false);
    }
}

sf::Mouse::Button InputView::sfmlMouseMacro(MouseCode mouseCode)
{
    switch(mouseCode)
    {
        case MouseCode::MOUSE_1:
            return sf::Mouse::Left;
        case MouseCode::MOUSE_2:
            return sf::Mouse::Right;
        case MouseCode::MOUSE_3:
            return sf::Mouse::Middle;
        case MouseCode::MOUSE_4:
            return sf::Mouse::XButton1;
        case MouseCode::MOUSE_5:
            return sf::Mouse::XButton2;
        default:
            // undefined behavior
            assert(false);
    }
}
