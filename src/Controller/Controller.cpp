#include "Controller.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "SoundManager.h"

Controller::Controller()
{
    this->shouldExit = false;

	this->controllerPackage = new ControllerPackage(new GraphicsManager(), new InputManager(), new SoundManager());
}

void Controller::Start()
{
    // Initialize the graphics library.
    GLFWwindow* window;
    glfwInit();
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    
    // Start the main game loop on a different thread.
    std::thread gameThread(&Controller::gameLoop, this);
    this->graphicsLoop(window);
    gameThread.join();
    
    glfwTerminate();
}

void Controller::gameLoop()
{
    GameStateManager manager(this->controllerPackage);
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

void Controller::graphicsLoop(GLFWwindow* window)
{
    GraphicsView graphicsView(this->controllerPackage);
    graphicsView.Initialize(window);
    graphicsView.OnWindowClose = [this] () { this->shouldExit = true; };
    
    while(!this->shouldExit)
    {
        double startTime = glfwGetTime();
        
        graphicsView.Update();
        
        while((glfwGetTime() - startTime) <= Controller::FRAMERATE)
        { }
    }
}