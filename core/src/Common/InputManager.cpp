#include "InputManager.h"
#include "InputView.h"
#include "KeyboardKeyPressEvent.h"
#include "KeyboardKeyReleaseEvent.h"
#include "MouseButtonPressEvent.h"
#include "MouseButtonReleaseEvent.h"
#include "JoystickButtonPressEvent.h"
#include "JoystickButtonReleaseEvent.h"
#include "JoystickAxisEvent.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::SetView(std::shared_ptr<InputView> inputView)
{
    this->inputView = inputView;
}

void InputManager::SetMouseInputMode(MouseInputMode mode)
{
    this->inputView.lock()->SetMouseInputMode(mode);
}

MouseInputMode InputManager::GetMouseInputMode()
{
    return this->inputView.lock()->GetMouseInputMode();
}

void InputManager::RegisterMouseMotionHandler(MouseMotionHandler handler)
{
    this->mouseMotionHandler = handler;
}

void InputManager::RegisterMouseButtonPressHandler(MouseButton button, MouseButtonPressHandler handler)
{
    this->mouseButtonPressHandlers[button] = handler;
}

void InputManager::RegisterMouseButtonReleaseHandler(MouseButton button, MouseButtonReleaseHandler handler)
{
    this->mouseButtonReleaseHandlers[button] = handler;
}

void InputManager::RegisterKeyboardKeyPressHandler(KeyboardKey key, KeyboardKeyPressHandler handler)
{
    this->keyboardKeyPressHandlers[key] = handler;
}

void InputManager::RegisterKeyboardKeyReleaseHandler(KeyboardKey key, KeyboardKeyReleaseHandler handler)
{
    this->keyboardKeyReleaseHandlers[key] = handler;
}

void InputManager::RegisterJoystickButtonPressHandler(unsigned int joystick, unsigned int button, JoystickButtonPressHandler handler)
{
    this->joystickButtonPressHandlers[joystick][button] = handler;
}

void InputManager::RegisterJoystickButtonReleaseHandler(unsigned int joystick, unsigned int button, JoystickButtonReleaseHandler handler)
{
    this->joystickButtonReleaseHandlers[joystick][button] = handler;
}

void InputManager::RegisterJoystickMotionHandler(unsigned int joystick, JoystickAxis axis, JoystickMotionHandler handler)
{
    this->joystickMotionHandlers[joystick][axis] = handler;
}

void InputManager::DeregisterMouseMotionHandler()
{
    this->mouseMotionHandler = nullptr;
}

void InputManager::DeregisterMouseButtonPressHandler(MouseButton button)
{
    this->mouseButtonPressHandlers.erase(button);
}

void InputManager::DeregisterMouseButtonReleaseHandler(MouseButton button)
{
    this->mouseButtonReleaseHandlers.erase(button);
}

void InputManager::DeregisterKeyboardKeyPressHandler(KeyboardKey key)
{
    this->keyboardKeyPressHandlers.erase(key);
}

void InputManager::DeregisterKeyboardKeyReleaseHandler(KeyboardKey key)
{
    this->keyboardKeyReleaseHandlers.erase(key);
}

void InputManager::DeregisterJoystickButtonPressHandler(unsigned int joystick, unsigned int button)
{
    this->joystickButtonPressHandlers[joystick][button] = nullptr;
}

void InputManager::DeregisterJoystickButtonReleaseHandler(unsigned int joystick, unsigned int button)
{
    this->joystickButtonReleaseHandlers[joystick][button] = nullptr;
}

void InputManager::DeregisterJoystickMotionHandler(unsigned int joystick, JoystickAxis axis)
{
    this->joystickMotionHandlers[joystick][axis] = nullptr;
}

bool InputManager::IsRegisteredEventHandler(KeyboardKey key)
{
    return (this->keyboardKeyPressHandlers[key]) || (this->keyboardKeyReleaseHandlers[key]);
}

InputState InputManager::GetKeyState(KeyboardKey key)
{
    return inputView.lock()->GetKeyboardKeyState(key);
}

InputState InputManager::GetMouseButtonState(MouseButton button)
{
    return inputView.lock()->GetMouseButtonState(button);
}

int InputManager::GetMouseX()
{
    return inputView.lock()->GetMouseX();
}

int InputManager::GetMouseY()
{
    return inputView.lock()->GetMouseY();
}

InputState InputManager::GetJoystickButtonState(unsigned int joystick, unsigned int button)
{
    return inputView.lock()->GetJoystickButtonState(joystick, button);
}


float InputManager::GetJoystickAxisValue(unsigned int joystick, JoystickAxis axis)
{
    return inputView.lock()->GetJoystickAxisValue(joystick, axis);
}

void InputManager::OnKeyboardKeyPress(KeyboardKeyPressEvent event) 
{
    KeyboardKeyPressHandler handler = this->keyboardKeyPressHandlers[event.key];
    if (handler)
    {
        handler(event);
    }
}

void InputManager::OnKeyboardKeyRelease(KeyboardKeyReleaseEvent event) 
{
    KeyboardKeyReleaseHandler handler = this->keyboardKeyReleaseHandlers[event.key];
    if (handler)
    {
        handler(event);
    }
}

void InputManager::OnMouseInput(MouseEvent event)
{
    if (this->mouseMotionHandler)
    {
        this->mouseMotionHandler(event);
    }
}

void InputManager::OnMouseButtonPress(MouseButtonPressEvent event)
{
    MouseButtonPressHandler handler = this->mouseButtonPressHandlers[event.button];
    if (handler)
    {
        handler(event);
    }
}

void InputManager::OnMouseButtonRelease(MouseButtonReleaseEvent event)
{
    MouseButtonReleaseHandler handler = this->mouseButtonReleaseHandlers[event.button];
    if (handler)
    {
        handler(event);
    }
}


void InputManager::OnJoystickButtonPress(JoystickButtonPressEvent event)
{
    JoystickButtonPressHandler handler = this->joystickButtonPressHandlers[event.joystick][event.button];
    if (handler)
    {
        handler(event);
    }
}

void InputManager::OnJoystickButtonRelease(JoystickButtonReleaseEvent event)
{
    JoystickButtonReleaseHandler handler = this->joystickButtonReleaseHandlers[event.joystick][event.button];
    if (handler)
    {
        handler(event);
    }
}

void InputManager::OnJoystickAxisInput(JoystickAxisEvent event)
{
    JoystickMotionHandler handler = this->joystickMotionHandlers[event.joystick][event.axis]; 
    if (handler)
    {
        handler(event);
    }
}
