#ifndef Core_GraphicsManager_h
#define Core_GraphicsManager_h

#include <set>
#include <iterator>
#include <mutex>
#include "Color.h"

class Sprite;

/**
 * Manages all graphical work provided by the engine.  Current functionality:
 *
 * Clear color: You may set a clear color via the engine's color class, or by
 * providing a float value for each color value.  These values must not be
 * zero.
 *
 * Sprite list: You may register and unregister sprites from the GraphicsManager.
 * Registered sprites are drawn according to their internal variables and can be
 * moved, resized, and recolored while they're registered, and this change will
 * be reflected in the view.
 *
 * It also provides a few other methods used internally within the engine.
 */
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
	Color GetClearColor();
	
	/**
	 * Sets the clear color
	 */
	void SetClearColor(Color clearColor);
	
	/**
	 * Sets the clear color
	 */
	void SetClearColor(float red, float blue, float green, float alpha);

	/**
	 * Registers a sprite to be drawn
	 *
	 * Throws an invalid_argument if the sprite was already registered.
	 */
	void RegisterSprite(Sprite* sprite);

	/**
	 * Unregisters a sprite so it will no longer be drawn
	 *
	 * Throws an invalid_argument if the sprite wasn't registered.
	 */
	void UnRegisterSprite(Sprite* sprite);

	/**
	 * Obtains the number of registered sprite.
	 */
	int GetSpriteCount();

	/**
	 * Prepares to add all sprites with the AddSpriteToVCIBuffer method
	 */
	void PrepareToAddSprites();

	/**
	 * Adds the next sprite's vertex, color, and index information to the
	 * given vertex buffer.
	 *
	 * Returns true if the sprite's data was successfully added; false if
	 * there are no more sprites to be added or PrepareToAddSprites hasn't
	 * been called.
	 * 
	 * DO NOT CALL THIS METHOD IF THERE IS NOT SPACE FOR 16 values for
	 * each sprite (16 * GetSpriteCount()).
	 */
	bool AddSpriteToVCIBuffer(float* vertexBuffer, float* colorBuffer, unsigned short* indexBuffer, unsigned short dataStartIndex);
    
private:
    // Private constructors to disallow access.
    GraphicsManager(GraphicsManager const &other);
    GraphicsManager operator=(GraphicsManager other);

	/**
	 * Clear color of screen
	 */
	Color clearColor;
	
	std::set<Sprite*> registeredSprites;
	std::mutex registeredSpritesMutex;
	std::set<Sprite*>::iterator spriteIterator;
};

#endif
