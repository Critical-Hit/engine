#include "InputManager.h"
#include "KeyPressEvent.h"
#include "KeyReleaseEvent.h"

InputManager::InputManager()
{
};

void InputManager::SetView(InputView* inputView)
{
	if (this->inputView != inputView)
	{
		this->inputView = inputView;
		inputView->SetManager(this);
	}
}

void InputManager::RegisterKeyPressEventHandler(IKeyPressEventHandler* handler, std::vector<KeyCode> keyCodes)
{
	for (KeyCode keyCode : keyCodes)
	{
        int intCode = static_cast<int>(keyCode);
		std::set<IKeyPressEventHandler*> handlers = this->registeredKeyPressEventHandlers[intCode];
		handlers.insert(handler);
		this->registeredKeyPressEventHandlers[intCode] = handlers;
	}
};

void InputManager::DeregisterKeyPressEventHandler(IKeyPressEventHandler* handler, std::vector<KeyCode> keyCodes)
{
	for (KeyCode keyCode : keyCodes)
    {
        int intCode = static_cast<int>(keyCode);
		std::set<IKeyPressEventHandler*> handlers = this->registeredKeyPressEventHandlers[intCode];
        handlers.erase(handler);
		this->registeredKeyPressEventHandlers[intCode] = handlers;
	}
};

void InputManager::RegisterKeyReleaseEventHandler(IKeyReleaseEventHandler* handler, std::vector<KeyCode> keyCodes)
{
	for (KeyCode keyCode : keyCodes)
	{
        int intCode = static_cast<int>(keyCode);
		std::set<IKeyReleaseEventHandler*> handlers =  this->registeredKeyReleaseEventHandlers[intCode];
		handlers.erase(handler);
		this->registeredKeyReleaseEventHandlers[intCode] = handlers;
	}
};

void InputManager::DeregisterKeyReleaseEventHandler(IKeyReleaseEventHandler* handler, std::vector<KeyCode> keyCodes)
{
	for (KeyCode keyCode : keyCodes)
	{
        int intCode = static_cast<int>(keyCode);
		std::set<IKeyReleaseEventHandler*> handlers = this->registeredKeyReleaseEventHandlers[intCode];
		handlers.erase(handler);
		this->registeredKeyReleaseEventHandlers[intCode] = handlers;
	}
};

InputState InputManager::GetKeyState(KeyCode keyCode)
{
    return inputView->GetKeyState(keyCode);
}

void InputManager::OnKeyPressEvent(KeyPressEvent* event) 
{
    int intCode = static_cast<int>(event->GetKeyCode());
    std::set<IKeyPressEventHandler*> handlers = this->registeredKeyPressEventHandlers[intCode];
    for (IKeyPressEventHandler* handler : handlers)
    {
       handler->OnKeyPressEvent(event);
    }
};

void InputManager::OnKeyReleaseEvent(KeyReleaseEvent* event) 
{
    int intCode = static_cast<int>(event->GetKeyCode());
    std::set<IKeyReleaseEventHandler*> handlers = this->registeredKeyReleaseEventHandlers[intCode];
    for (IKeyReleaseEventHandler* handler : handlers)
    {
       handler->OnKeyReleaseEvent(event);
    }
};
