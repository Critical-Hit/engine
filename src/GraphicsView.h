#ifndef Core_GraphicsView_h
#define Core_GraphicsView_h

#include <GLFW/glfw3.h>
#include <functional>

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
     * Updates the GraphicsView.
     */
    void Update(float green);
    
    /**
     * Function to call if the user attempts to close the GLFW Window.
     */
    std::function<void(void)> OnWindowClose;
    
private:
    GraphicsView(GraphicsView const &other);
    GraphicsView operator=(GraphicsView other);
    
    /**
     * The GLFW Window to draw to.
     */
    GLFWwindow* window;
};

#endif
