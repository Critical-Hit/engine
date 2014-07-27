#ifndef Core_Color_h
#define Core_Color_h

#include <string>

/**
 * A color is an immutable clas made up of a red, green, blue,
 * and alpha value.
 */
class Color final
{
public:
	/**
	 * Default constructor, creating black
	 */
	Color();

	/**
	 * Creates a color with the given values.
	 *
	 * No color values may be less than zero.
	 */
	Color(float red, float green, float blue, float alpha);

	/**
	 * Creates a color with the given values and an alpha of 1.0
	 *
	 * No color values may be less than zero.
	 */
	Color(float red, float green, float blue);

	/**
	 * Basic copy constructor
	 */
	Color(const Color& other);

	/**
	 * Basic assignment constructor
	 */
	Color operator=(const Color& other);

	/**
	 * Basic destructor
	 */
	~Color();
	
	/**
	 * Turns the color into a string formatted as:
	 *
	 * "(red, blue, green, alpha)"
	 */
	std::string ToString();

	float red;
	float green;
	float blue;
	float alpha;

private:
	/**
	 * Validates that no color channels are less than zero.
	 */
	void validateChannels();
};

#endif