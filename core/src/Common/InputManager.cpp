#include "InputManager.h"
#include "InputView.h"
#include "KeyboardKeyPressEvent.h"
#include "KeyboardKeyReleaseEvent.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::CopyFrom(InputManager* other)
{
    this->inputView = other->inputView; 
    this->registeredKeyboardInputEventHandlers = other->registeredKeyboardInputEventHandlers;
    this->registeredMouseInputEventHandlers = other->registeredMouseInputEventHandlers;
}

void InputManager::SetView(InputView* inputView)
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

void InputManager::RegisterKeyboardInputEventHandler(IInputEventHandler* handler, std::vector<KeyboardKey> keys)
{
    for (KeyboardKey key : keys) 
    {
        int intCode = static_cast<int>(key);
        std::set<IInputEventHandler*> handlers = this->registeredKeyboardInputEventHandlers[intCode];
        handlers.insert(handler);
        this->registeredKeyboardInputEventHandlers[intCode] = handlers;
    }
}

void InputManager::DeregisterKeyboardInputEventHandler(IInputEventHandler* handler, std::vector<KeyboardKey> keyCodes)
{
    for (KeyboardKey keyCode : keyCodes)
    {
        int intCode = static_cast<int>(keyCode);
        std::set<IInputEventHandler*> handlers = this->registeredKeyboardInputEventHandlers[intCode];
        handlers.erase(handler);
        this->registeredKeyboardInputEventHandlers[intCode] = handlers;
    }
};

bool InputManager::IsRegisteredEventHandler(KeyboardKey* keyCode)
{
    int intCode = static_cast<int>(*keyCode);
    std::set<IInputEventHandler*>* handlers = &(this->registeredKeyboardInputEventHandlers[intCode]);
    return handlers->size() != 0;
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
    int intCode = static_cast<int>(event->GetKeyboardKey());
    std::set<IInputEventHandler*> handlers = this->registeredKeyboardInputEventHandlers[intCode];
    for (IInputEventHandler* handler : handlers)
    {
        handler->OnKeyboardKeyPress(event);
    }
};

void InputManager::OnKeyboardKeyRelease(KeyboardKeyReleaseEvent* event) 
{
    int intCode = static_cast<int>(event->GetKeyboardKey());
    std::set<IInputEventHandler*> handlers = this->registeredKeyboardInputEventHandlers[intCode];
    for (IInputEventHandler* handler : handlers)
    {
        handler->OnKeyboardKeyRelease(event);
    }
};

void InputManager::OnMouseInput(MouseEvent* event)
{
    for (IInputEventHandler* handler : registeredMouseInputEventHandlers)
    {
        handler->OnMouseInput(event);
    }
}

void InputManager::OnMouseButtonPress(MouseButtonPressEvent* event)
{
    for (IInputEventHandler* handler : registeredMouseInputEventHandlers)
    {
        handler->OnMouseButtonPress(event);
    }
}

void InputManager::OnMouseButtonRelease(MouseButtonReleaseEvent* event)
{
    for (IInputEventHandler* handler : registeredMouseInputEventHandlers)
    {
        handler->OnMouseButtonRelease(event);
    }
}
