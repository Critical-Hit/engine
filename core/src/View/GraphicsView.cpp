#include <stdexcept>
#include <string>
#include "GraphicsView.h"
#include "Sprite.h"
#include "SFML/OpenGL.hpp"

GraphicsView::GraphicsView(std::shared_ptr<sf::Window> window)
{
    this->window = window;
}

GraphicsView::~GraphicsView()
{
}

void GraphicsView::Initialize()
{

}

void GraphicsView::Update(std::shared_ptr<View::IGraphicsManager> graphicsManager)
{
    // Allocate buffers
    float* vertexBuffer;
    float* colorBuffer;
    unsigned short* indexBuffer;
    vertexBuffer = new float[4 * 4]; // 4 vertices; 4 coordinates per vertex
    colorBuffer = new float[4 * 4]; // 4 vertices; 4 channels per vertex
    indexBuffer = new unsigned short[2 * 3]; // 2 triangles; 3 indices per triangle
    
    // Clear the screen
    Color clearColor = graphicsManager->GetClearColor();
    glClearColor(clearColor.red, clearColor.green, clearColor.blue, clearColor.alpha);
    glClear(GL_COLOR_BUFFER_BIT);
    GraphicsView::CheckOpenGLError("after clearing the screen");
    
    // Prepare the matrices
    glLoadIdentity();
    std::shared_ptr<Camera> camera = graphicsManager->GetCamera();
    float left = camera->GetLeft();
    float right = camera->GetRight();
    float bottom = camera->GetBottom();
    float top = camera->GetTop();
    glOrtho(left, right, bottom, top, -1.0f, 1000.0f);
    GraphicsView::CheckOpenGLError("after preparing matrices");
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(4, GL_FLOAT, 0, vertexBuffer);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(4, GL_FLOAT, 0, colorBuffer);
    
    // Draw sprites
    graphicsManager->PrepareToAddSprites();
    while(graphicsManager->AddSpriteToVCIBuffer(vertexBuffer, colorBuffer, indexBuffer, 0))
    {
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indexBuffer);
    }
    GraphicsView::CheckOpenGLError("after drawing sprites");
    
    // Swap the buffers
    this->window->display();
    GraphicsView::CheckOpenGLError("after swapping buffers");
    
    // release buffer memory
    delete[] vertexBuffer;
    delete[] colorBuffer;
    delete[] indexBuffer;
    
    GraphicsView::CheckOpenGLError("at end of Update()");
}

void GraphicsView::CheckOpenGLError(std::string location)
{
    GLenum error = glGetError();
    switch (error)
    {
    case GL_NO_ERROR:
        return;
    case GL_INVALID_ENUM:
        throw new std::logic_error("There was an OpenGL Invalid Enum error " + location);
    case GL_INVALID_VALUE:
        throw new std::logic_error("There was an OpenGL Invalid Value error " + location);
    case GL_INVALID_OPERATION:
        throw new std::logic_error("There was an OpenGL Invalid Operation error " + location);
    case GL_OUT_OF_MEMORY:
        throw new std::logic_error("There was an OpenGL Out of Memory error " + location);
    case GL_STACK_UNDERFLOW:
        throw new std::logic_error("There was an OpenGL Stack Underflow error " + location);
    case GL_STACK_OVERFLOW:
        throw new std::logic_error("There was an OpenGL Stack Overflow error " + location);
    }
}
