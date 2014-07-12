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
	// Clear the screen
	glClearColor(0.0f, this->graphicsManager->GetClearColor(), this->graphicsManager->GetClearColor(), 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
	// Draw a triangle
	float vertex[] =
	{
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};
	float color[] = 
	{
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f
	};
	GLubyte indeces[] =
	{
		0, 1, 2, 2, 3, 0
	};
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertex);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, color);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indeces);
	
	// Swap the buffers
	glfwSwapBuffers(this->window);
    glfwPollEvents();
    
    // Call OnWindowClose if the user closed the Window.
    if(glfwWindowShouldClose(window) && this->OnWindowClose != NULL)
    {
        this->OnWindowClose();
    }
}