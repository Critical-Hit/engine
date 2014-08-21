#include "InputManager.h"
#include "InputView.h"
#include "KeyPressEvent.h"
#include "KeyReleaseEvent.h"

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

void InputManager::RegisterKeyboardInputEventHandler(IInputEventHandler* handler, std::vector<KeyCode> keyCodes)
{
    for (KeyCode keyCode : keyCodes)
    {
        int intCode = static_cast<int>(keyCode);
        std::set<IInputEventHandler*> handlers = this->registeredKeyboardInputEventHandlers[intCode];
        handlers.insert(handler);
        this->registeredKeyboardInputEventHandlers[intCode] = handlers;
    }
}

void InputManager::DeregisterKeyboardInputEventHandler(IInputEventHandler* handler, std::vector<KeyCode> keyCodes)
{
    for (KeyCode keyCode : keyCodes)
    {
        int intCode = static_cast<int>(keyCode);
        std::set<IInputEventHandler*> handlers = this->registeredKeyboardInputEventHandlers[intCode];
        handlers.erase(handler);
        this->registeredKeyboardInputEventHandlers[intCode] = handlers;
    }
};

bool InputManager::IsRegisteredEventHandler(KeyCode* keyCode)
{
    int intCode = static_cast<int>(*keyCode);
    std::set<IInputEventHandler*>* handlers = &(this->registeredKeyboardInputEventHandlers[intCode]);
    return handlers->size() != 0;
}


InputState InputManager::GetKeyState(KeyCode keyCode)
{
    return inputView->GetKeyState(keyCode);
}

InputState InputManager::GetMouseButtonState(MouseCode mouseCode)
{
    return inputView->GetMouseButtonState(mouseCode);
}

int InputManager::GetMouseAbsoluteX()
{
    return inputView->GetMouseAbsoluteX();
}

int InputManager::GetMouseAbsoluteY()
{
    return inputView->GetMouseAbsoluteY();
}

void InputManager::OnKeyboardKeyPress(KeyPressEvent* event) 
{
    int intCode = static_cast<int>(event->GetKeyCode());
    std::set<IInputEventHandler*> handlers = this->registeredKeyboardInputEventHandlers[intCode];
    for (IInputEventHandler* handler : handlers)
    {
        handler->OnKeyboardKeyPress(event);
    }
};

void InputManager::OnKeyboardKeyRelease(KeyReleaseEvent* event) 
{
    int intCode = static_cast<int>(event->GetKeyCode());
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
