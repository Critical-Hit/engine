#include "Controller.h"

Controller::Controller()
{
    this->colorValue = 0.0f;
    this->shouldExit = false;
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
    int sign = -1;
    float increment = 0.016667f;
    while(!this->shouldExit)
    {
        double startTime = glfwGetTime();
        
        // For now just alternate between a 0 and 1 color value to flash a color.
        if(this->colorValue <= 0.0f || this->colorValue >= 1.0f)
        {
            sign *= -1;
        }
        this->colorValue += (sign * increment);
        
        while((glfwGetTime() - startTime) <= Controller::UPDATE_RATE)
        { }
    }
}

void Controller::graphicsLoop(GLFWwindow* window)
{
    GraphicsView graphicsView;
    graphicsView.Initialize(window);
    graphicsView.OnWindowClose = [this] () { this->shouldExit = true; };
    
    while(!this->shouldExit)
    {
        double startTime = glfwGetTime();
        
        graphicsView.Update(this->colorValue);
        
        while((glfwGetTime() - startTime) <= Controller::FRAMERATE)
        { }
    }
}