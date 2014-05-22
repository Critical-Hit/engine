#include "GraphicsView.h"

GraphicsView::GraphicsView()
{
    
}

void GraphicsView::Initialize(GLFWwindow* window)
{
    this->window = window;
}

void GraphicsView::Update(float colorValue)
{
    // Update and render your GraphicsView here.
    glClearColor(0.0f, colorValue, colorValue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(this->window);
    glfwPollEvents();
    
    // Call OnWindowClose if the user closed the Window.
    if(glfwWindowShouldClose(window) && this->OnWindowClose != NULL)
    {
        this->OnWindowClose();
    }
}