#include "GraphicsView.h"

GraphicsView::GraphicsView()
{

}

GraphicsView::~GraphicsView()
{
    glfwTerminate();
}

void GraphicsView::Initialize()
{
    // Initialize the graphics library.
    // @TODO: GLFW window scope should be Controller, not View.
    // Transfer control of window to Controller
    GLFWwindow* window;
    glfwInit();
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    this->window = window;
}

void GraphicsView::Update(GraphicsManager* graphicsManager)
{
    glClearColor(0.0f, graphicsManager->GetClearColor(), graphicsManager->GetClearColor(), 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(this->window);
    glfwPollEvents();
    
    // Call OnWindowClose if the user closed the Window.
    if(glfwWindowShouldClose(window) && this->OnWindowClose != NULL)
    {
        this->OnWindowClose();
    }
}
