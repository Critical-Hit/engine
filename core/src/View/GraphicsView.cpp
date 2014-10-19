#include <stdexcept>
#include <string>
#include "GraphicsView.h"
#include "Sprite.h"

GraphicsView::GraphicsView(std::shared_ptr<sf::Window> window)
{
    this->window = window;
}

GraphicsView::~GraphicsView()
{
}

void GraphicsView::Initialize()
{
    // Prepare Test Texture
    GLubyte textureArray[] =
    {
        255, 0, 0, 255, 0, 255, 0, 255,
        0, 0, 255, 0, 255, 255, 0, 255
    };
    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureArray);
    this->testTextureId = textureId;
}

void GraphicsView::Update(std::shared_ptr<GraphicsManager> graphicsManager)
{
    // Allocate buffers
    float* vertexBuffer = new float[4 * 4]; // 4 vertices; 4 coordinates per vertex
    float* colorBuffer = new float[4 * 4]; // 4 vertices; 4 channels per vertex
    unsigned short* indexBuffer = new unsigned short[2 * 3]; // 2 triangles; 3 indices per triangle
    float textureCoordBuffer[] =
    {
        0.0f, 0.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 0.0f, 1.0f
    };
    
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
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, textureCoordBuffer);

    glEnable(GL_TEXTURE_2D);
    
    // Draw sprites
    graphicsManager->PrepareToAddSprites();
    while(graphicsManager->AddSpriteToVCIBuffer(vertexBuffer, colorBuffer, indexBuffer, 0))
    {
        if (graphicsManager->GetCurrentRenderMode() == SpriteRenderMode::Textured)
        {
            glDisableClientState(GL_COLOR_ARRAY);
            glBindTexture(GL_TEXTURE_2D, this->testTextureId);
        }
        else
        {
            glEnableClientState(GL_COLOR_ARRAY);
            glColorPointer(4, GL_FLOAT, 0, colorBuffer);
            glBindTexture(GL_TEXTURE_2D, 0);
        }
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
