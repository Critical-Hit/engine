#ifndef Core_GraphicsView_h
#define Core_GraphicsView_h

#include <GLFW/glfw3.h>
#include <functional>

#include "ControllerPackage.h"
#include "GraphicsManager.h"
#include "Texture.h"

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
    GraphicsView(ControllerPackage* controllerPackage);
    
    /**
     * Initializes the GraphicsView.
     */
    void Initialize(GLFWwindow* window);
    
    /**
     * Updates the GraphicsView.
     */
    void Update();
    
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
	 * GraphicsManager with information about what to draw
	 */
	GraphicsManager* const graphicsManager;
};

#endif
