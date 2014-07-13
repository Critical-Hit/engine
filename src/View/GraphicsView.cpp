#include "GraphicsView.h"
#include "Sprite.h"

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
	Color clearColor = graphicsManager->GetClearColor();
	glClearColor(clearColor.red, clearColor.green, clearColor.blue, clearColor.alpha);
	glClear(GL_COLOR_BUFFER_BIT);

	bool doTestTexturing = false;
	GLuint texture;
	float* textureCoords;

	if (doTestTexturing)
	{
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		int width;
		int height;
		GLubyte data[] =
		{
			255, 0, 0, 255, 0, 255, 0, 255,

			0, 0, 255, 255, 255, 255, 0, 255,
		};

		float coords[] =
		{
			1.0f, 0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 0.0f,
		};
		textureCoords = coords;

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}

	bool spriteTest = true;
	Sprite sprite(-0.5f, 0.5f, 1.0f, 1.0f, Color(0.0f, 1.0f, 0.0f, 1.0f));
	float* vertexBuffer;
	float* colorBuffer;
	GLubyte* indexBuffer;

	if (!spriteTest)
	{
		float vertex[] =
		{
			0.5f, 0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, 0.5f, 0.0f, 1.0f,
		};
		float color[] =
		{
			0.0f, 0.0f, 1.0f, 1.0f,
			0.0f, 0.0f, 1.0f, 1.0f,
			0.0f, 0.0f, 1.0f, 1.0f,
			0.0f, 0.0f, 1.0f, 1.0f,
		};
		GLubyte indeces[] =
		{
			0, 1, 2, 2, 3, 0
		};
		vertexBuffer = vertex;
		colorBuffer = color;
		indexBuffer = indeces;
	}
	else
	{
		vertexBuffer = new float[16];
		sprite.PutGLVertexInfo(vertexBuffer);
		colorBuffer = new float[16];
		sprite.PutGLColorInfo(colorBuffer);
		indexBuffer = new GLubyte[6];
		sprite.PutGLIndexInfoChar((char*)indexBuffer, 0);
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(4, GL_FLOAT, 0, vertexBuffer);
	if (!doTestTexturing)
	{
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(4, GL_FLOAT, 0, colorBuffer);
	}
	else
	{
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, 0, textureCoords);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indexBuffer);
	
	// Swap the buffers
	glfwSwapBuffers(this->window);
    glfwPollEvents();
    
    // Call OnWindowClose if the user closed the Window.
    if(glfwWindowShouldClose(window) && this->OnWindowClose != NULL)
    {
        this->OnWindowClose();
    }
}