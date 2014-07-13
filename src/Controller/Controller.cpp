#include "Controller.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "SoundManager.h"

Controller::Controller()
{
    this->shouldExit = false;
}

void Controller::Start()
{
    // Start the main game loop on a different thread.
    std::thread gameThread(&Controller::gameLoop, this);
    this->viewLoop();
    gameThread.join();
}

void Controller::gameLoop()
{
    GameStateManager manager;
    manager.Initialize(new InitialState());
    
    int i = 0;
    while(!this->shouldExit)
    {
        i++;
        double startTime = glfwGetTime();

        manager.Update();
        
        while((glfwGetTime() - startTime) <= Controller::UPDATE_RATE)
        { }
    }
}

void Controller::viewLoop()
{
    GraphicsView graphicsView; 
    graphicsView.Initialize();
    graphicsView.OnWindowClose = [this] () { this->shouldExit = true; };
    InputView inputView;
    inputView.Initialize();
    SoundView soundView;
    soundView.Initialize();

    while(!this->shouldExit)
    {
        double startTime = glfwGetTime();
        
        graphicsView.Update(ControllerPackage::GetActiveControllerPackage()->GetGraphicsManager());
        inputView.Update(ControllerPackage::GetActiveControllerPackage()->GetInputManager());
        soundView.Update(ControllerPackage::GetActiveControllerPackage()->GetSoundManager());
        
        while((glfwGetTime() - startTime) <= Controller::FRAMERATE)
        { }
    }
}