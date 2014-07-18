#include "GraphicsView.h"

GraphicsView::GraphicsView(ControllerPackage* controllerPackage)
: graphicsManager(controllerPackage->GetGraphicsManager())
{

}

void GraphicsView::Initialize(GLFWwindow* window)
{
    GLuint tex_2d = SOIL_load_OGL_texture
    (
     "meeseeks.png",
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
    
    if(tex_2d == 0)
    {
        printf("Error loading Image");
    }
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