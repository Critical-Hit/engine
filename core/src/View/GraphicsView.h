#ifndef Core_GraphicsView_h
#define Core_GraphicsView_h

#include <SFML/Window.hpp>
#include <functional>
#include <memory>

#include "ControllerPackage.h"
#include "IGraphicsManagerView.h"
#include "Texture.h"

class string;

/**
 * Provides a full set of logic for displaying graphics.
 * 
 **/
class GraphicsView
{
public:
    /**
     * Constructs a GraphicsView with a given controller package.
     */
    GraphicsView(std::shared_ptr<sf::Window> window);
    
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
    void Update(std::shared_ptr<View::IGraphicsManager> graphicsManager);

private:
    // Private constructors to disallow access.
    GraphicsView(GraphicsView const &other);
    GraphicsView operator=(GraphicsView other);

    /**
     * The SMFL Window to draw to.
     */
    std::shared_ptr<sf::Window> window;

    /**
     * Utility function for checking OpenGL errors
     */
    void CheckOpenGLError(std::string location);
};

#endif
