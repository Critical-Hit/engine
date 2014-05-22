#ifndef Core_GraphicsView_h
#define Core_GraphicsView_h

#include <GLFW/glfw3.h>
#include <functional>

/**
 * Provides a full set of logic for displaying graphics.
 * 
 * Currently, this is simply cleraing to a particular color, given to the
 * update method.
 */
class GraphicsView
{
public:
    /**
     * Default constructor that creates a new instance of a Controller.
     */
    GraphicsView();
    
    /**
     * Initializes the GraphicsView.
     */
    void Initialize(GLFWwindow* window);
    
    /**
     * Updates the GraphicsView, causing it to clear the screen to the
	 * given color value.
     */
    void Update(float colorValue);
    
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
};

#endif
