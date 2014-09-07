#include "InputManager.h"
#include "InputView.h"
#include "KeyboardKeyPressEvent.h"
#include "KeyboardKeyReleaseEvent.h"
#include "MouseButtonPressEvent.h"
#include "MouseButtonReleaseEvent.h"

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
    this->inputView->SetMouseInputMode(mode);
}

MouseInputMode InputManager::GetMouseInputMode()
{
    return this->inputView->GetMouseInputMode();
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

bool InputManager::IsRegisteredEventHandler(KeyboardKey key)
{
    return (this->keyboardKeyPressHandlers[key]) || (this->keyboardKeyReleaseHandlers[key]);
}

InputState InputManager::GetKeyState(KeyboardKey key)
{
    return inputView->GetKeyboardKeyState(key);
}

InputState InputManager::GetMouseButtonState(MouseButton button)
{
    return inputView->GetMouseButtonState(button);
}

int InputManager::GetMouseX()
{
    return inputView->GetMouseX();
}

int InputManager::GetMouseY()
{
    return inputView->GetMouseY();
}

void InputManager::OnKeyboardKeyPress(KeyboardKeyPressEvent* event) 
{
    if (this->keyboardKeyPressHandlers[event->GetKeyboardKey()])
    {
        this->keyboardKeyPressHandlers[event->GetKeyboardKey()](event);
    }
}

void InputManager::OnKeyboardKeyRelease(KeyboardKeyReleaseEvent* event) 
{
    if (this->keyboardKeyReleaseHandlers[event->GetKeyboardKey()])
    {
        this->keyboardKeyReleaseHandlers[event->GetKeyboardKey()](event);
    }
}

void InputManager::OnMouseInput(MouseEvent* event)
{
    if (this->mouseMotionHandler)
    {
        this->mouseMotionHandler(event);
    }
}

void InputManager::OnMouseButtonPress(MouseButtonPressEvent* event)
{
    if (this->mouseButtonPressHandlers[event->GetMouseButton()])
    {
        this->mouseButtonPressHandlers[event->GetMouseButton()](event);
    }
}

void InputManager::OnMouseButtonRelease(MouseButtonReleaseEvent* event)
{
    if (this->mouseButtonReleaseHandlers[event->GetMouseButton()])
    {
        this->mouseButtonReleaseHandlers[event->GetMouseButton()](event);
    }
}
