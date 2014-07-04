#include "GraphicsView.h"

GraphicsView::GraphicsView(ControllerPackage* controllerPackage)
: graphicsManager(controllerPackage->GetGraphicsManager())
{

}

void GraphicsView::Initialize(GLFWwindow* window)
{
    this->window = window;
}

void GraphicsView::Update()
{
	glClearColor(0.0f, this->graphicsManager->GetClearColor(), this->graphicsManager->GetClearColor(), 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(this->window);
    glfwPollEvents();
    
    // Call OnWindowClose if the user closed the Window.
    if(glfwWindowShouldClose(window) && this->OnWindowClose != NULL)
    {
        this->OnWindowClose();
    }
}