#ifndef Core_Sprite_h
#define Core_Sprite_h

#include <assert.h>
#include "Color.h"

/**
 * Sprites are a 2D rectangle that can be drawn on the scren.
 * They have a position, width, height, and a color.  In the
 * future, support for texturing and more advanced
 * transformations such as rotation will be added.
 *
 * The position is the top-left corner of the sprite.
 */
class Sprite
{
public:
	/**
	 * Basic constructor for the sprite class
	 *
	 * Width and height must both be greater than zero.
	 */
	inline Sprite(float x, float y, float width, float height, Color);

	/**
	 * Moves the sprite to the given location
	 */
	void inline MoveTo(float x, float y);

	/**
	 * Moves the sprite by the given amount in the x and y
	 * direction
	 */
	void inline MoveBy(float dx, float dy);

	/**
	 * Changes the width to the given value
	 *
	 * Width must be greater than zero.
	 */
	void inline ChangeWidth(float width);

	/**
	 * Changes the height to the given value
	 *
	 * Height must be greater than zero.
	 */
	void inline ChangeHeight(float height);

	/**
	 * Changes the dimensions of the sprite to the given value
	 *
	 * Width and height must both be greater than zero.
	 */
	void inline ChangeDimensions(float width, float height);

	/**
	 * Changes the color of the sprite
	 */
	void inline ChangeColor(Color color);

	/**
	 * Obtains x
	 */
	float inline GetX();

	/**
	 * Obtains y
	 */
	float inline GetY();

	/**
	 * Obtains width
	 */
	float inline GetWidth();

	/**
	 * Obtains height
	 */
	float inline GetHeight();

	/**
	 * Obtains the sprite's color
	 */
	Color inline GetColor();

protected:
	float x;
	float y;
	float width;
	float height;
	Color color;

	/**
	 * Validates that width and height are greater than zero.
	 */
	void inline validateDimensions();

private:
	Sprite operator=(Sprite& other);
	Sprite(Sprite& other);
};

#include "SpriteInline.h"

#endif