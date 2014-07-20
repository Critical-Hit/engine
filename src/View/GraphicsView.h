#ifndef Core_GraphicsView_h
#define Core_GraphicsView_h

#include <GLFW/glfw3.h>
#include <functional>

#include "ControllerPackage.h"
#include "GraphicsManager.h"

/**
 * Provides a full set of logic for displaying graphics.
 * 
 * Currently, this is simply clearing to a particular color.
 */
class GraphicsView
{
public:
    /**
     * Constructs a GraphicsView with a given controller package.
     */
    GraphicsView(GLFWwindow* window);
    
    /**
     * Destructor for GraphicsView
     */
    ~GraphicsView();

    /**
     * Initializes the GraphicsView.
     */
    void Initialize();
    
    /**
     * Updates the GraphicsView.
     */
    void Update(GraphicsManager* graphicsManager);
    
    /**
     * Function to call if the user attempts to close the GLFW Window.
     */
    std::function<void(void)> OnWindowClose;
    
private:
    // Private constructors to disallow access.
    GraphicsView(GraphicsView const &other);
    GraphicsView operator=(GraphicsView other);
    
    /**
     * The GLFW Window to draw to.
     */
    GLFWwindow* window;

    /**
	 * Utility function for checking OpenGL errors
	 */
	void CheckOpenGLError();

};

#endif
