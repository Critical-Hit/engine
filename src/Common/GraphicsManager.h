#ifndef Core_GraphicsManager_h
#define Core_GraphicsManager_h

class GraphicsManager
{
public:
    /**
     * Default constructor that creates a new instance of a Controller.
     */
    GraphicsManager();
    
private:
    // Private constructors to disallow access.
    GraphicsManager(GraphicsManager const &other);
    GraphicsManager operator=(GraphicsManager other);
};

#endif
