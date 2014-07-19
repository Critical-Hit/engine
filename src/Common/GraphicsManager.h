#ifndef Core_GraphicsManager_h
#define Core_GraphicsManager_h

class GraphicsManager
{
public:
    /**
     * Default constructor that creates a new instance of a GraphicsManager.
     */
    GraphicsManager();

	/**
	 * Destructor
	 */
	~GraphicsManager();

	/**
	 * Gets the clear color
	 */
	float GetClearColor();
	
	/**
	 * Sets the clear color
	 */
	void SetClearColor(float clearColor);

	/**
	 * Sets all variables of this instance to match the other instance.
	 */
	void CopyFrom(GraphicsManager* other);
    
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
