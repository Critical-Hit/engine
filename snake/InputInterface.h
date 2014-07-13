#include <functional>
#include <thread>
#include "InputManager.h"

class InputInterface
{
public:
    InputInterface() 
    {
        
    }

    void Initialize(InputManager* inputManager)
    {
        this->inputManager = inputManager;
    }

    InputManager* inputManager;

    /**
    * Functions to call when keys are pressed
    */
    std::function<void(void)> OnEnterPressed;
    std::function<void(void)> OnEscapePressed;
    std::function<void(void)> OnWPressed;
    std::function<void(void)> OnAPressed;
    std::function<void(void)> OnSPressed;
    std::function<void(void)> OnDPressed;
    std::function<void(void)> OnWReleased;
    std::function<void(void)> OnAReleased;
    std::function<void(void)> OnSReleased;
    std::function<void(void)> OnDReleased;
};