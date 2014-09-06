#ifndef Core_GraphicsView_h
#define Core_GraphicsView_h

#include <GLFW/glfw3.h>
#include <SFML/Window.hpp>
#include <functional>

#include "ControllerPackage.h"
#include "GraphicsManager.h"
#include "Texture.h"

class string;

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
    GraphicsView(sf::Window* window);

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
    sf::Window* window;

    /**
     * Utility function for checking OpenGL errors
     */
    void CheckOpenGLError(std::string location);
};

#endif
