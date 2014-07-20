#include "GraphicsView.h"

GraphicsView::GraphicsView()
{
}

GraphicsView::~GraphicsView()
{
}

void GraphicsView::Initialize(GLFWwindow* window)
{
    // Initialize the graphics library.
    this->window = window;
}

void GraphicsView::Update(GraphicsManager* graphicsManager)
{
    glClearColor(0.0f, graphicsManager->GetClearColor(), graphicsManager->GetClearColor(), 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(this->window);
}
