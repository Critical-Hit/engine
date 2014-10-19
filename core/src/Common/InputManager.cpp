#include "IInputManager.h"
#include "IInputManagerView.h"
#include "InputView.h"
#include "ManagerCast.h"
#include "KeyboardKeyPressEvent.h"
#include "KeyboardKeyReleaseEvent.h"
#include "MouseButtonPressEvent.h"
#include "MouseButtonReleaseEvent.h"
#include <map>
#include <memory>

class InputManager : public View::IInputManager, public Model::IInputManager
{
public:
    InputManager();

    ~InputManager();

    void SetView(std::shared_ptr<InputView> inputView);

    void SetMouseInputMode(MouseInputMode mode);

    MouseInputMode GetMouseInputMode();

    void RegisterMouseMotionHandler(MouseMotionHandler handler);

    void RegisterMouseButtonPressHandler(MouseButton button, MouseButtonPressHandler handler);

    void RegisterMouseButtonReleaseHandler(MouseButton button, MouseButtonReleaseHandler handler);

    void RegisterKeyboardKeyPressHandler(KeyboardKey key, KeyboardKeyPressHandler handler);

    void RegisterKeyboardKeyReleaseHandler(KeyboardKey key, KeyboardKeyReleaseHandler handler);

    void DeregisterMouseMotionHandler();   

    void DeregisterMouseButtonPressHandler(MouseButton button);

    void DeregisterMouseButtonReleaseHandler(MouseButton button);

    void DeregisterKeyboardKeyPressHandler(KeyboardKey key);

    void DeregisterKeyboardKeyReleaseHandler(KeyboardKey key);

    bool IsRegisteredEventHandler(KeyboardKey key);

    InputState GetKeyState(KeyboardKey key);

    InputState GetMouseButtonState(MouseButton button);

    int GetMouseX();

    int GetMouseY();

    void OnKeyboardKeyPress(KeyboardKeyPressEvent event);

    void OnKeyboardKeyRelease(KeyboardKeyReleaseEvent event);

    void OnMouseInput(MouseEvent event);

    void OnMouseButtonPress(MouseButtonPressEvent event);

    void OnMouseButtonRelease(MouseButtonReleaseEvent event);

private:
    // Private constructors to disallow access.
    InputManager(InputManager const &other);
    InputManager operator=(InputManager other);

    // InputView which is polled for ondemand input.
    std::weak_ptr<InputView> inputView;

    // Registered event handlers
    MouseMotionHandler mouseMotionHandler;
    std::map<MouseButton, MouseButtonPressHandler> mouseButtonPressHandlers;
    std::map<MouseButton, MouseButtonReleaseHandler> mouseButtonReleaseHandlers;
    std::map<KeyboardKey, KeyboardKeyPressHandler> keyboardKeyPressHandlers;
    std::map<KeyboardKey, KeyboardKeyReleaseHandler> keyboardKeyReleaseHandlers;
};

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

void InputManager::OnKeyboardKeyPress(KeyboardKeyPressEvent event) 
{
    if (this->keyboardKeyPressHandlers[event.key])
    {
        this->keyboardKeyPressHandlers[event.key](event);
    }
}

void InputManager::OnKeyboardKeyRelease(KeyboardKeyReleaseEvent event) 
{
    if (this->keyboardKeyReleaseHandlers[event.key])
    {
        this->keyboardKeyReleaseHandlers[event.key](event);
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
    if (this->mouseButtonPressHandlers[event.button])
    {
        this->mouseButtonPressHandlers[event.button](event);
    }
}

void InputManager::OnMouseButtonRelease(MouseButtonReleaseEvent event)
{
    if (this->mouseButtonReleaseHandlers[event.button])
    {
        this->mouseButtonReleaseHandlers[event.button](event);
    }
}

// Hidden class pattern methods

std::shared_ptr<Model::IInputManager> Model::CreateIInputManager()
{
    return std::dynamic_pointer_cast<Model::IInputManager, InputManager>(std::make_shared<InputManager>());
}

std::shared_ptr<View::IInputManager> View::CreateIInputManager()
{
    return std::dynamic_pointer_cast<View::IInputManager, InputManager>(std::make_shared<InputManager>());
}

std::shared_ptr<View::IInputManager> ManagerCast::CastInputManagerToInputManagerView(std::shared_ptr<Model::IInputManager> manager)
{
    return std::dynamic_pointer_cast<View::IInputManager, Model::IInputManager>(manager);
}

