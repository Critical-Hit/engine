#ifndef Core_GraphicsManager_h
#define Core_GraphicsManager_h

class GraphicsManager
{
public:
    /**
     * Default constructor that creates a new instance of a Controller.
     */
    GraphicsManager();

	/**
	 * Gets the clear color
	 */
	float GetClearColor();
	
	/**
	 * Sets the clear color
	 */
	void SetClearColor(float clearColor);
    
private:
    // Private constructors to disallow access.
    GraphicsManager(GraphicsManager const &other);
    GraphicsManager operator=(GraphicsManager other);

	/**
	* Clear color of screen
	*/
	float clearColor;
};

#endif
