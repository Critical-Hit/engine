#ifndef Core_Color_h
#define Core_Color_h

/**
 * A color is an immutable clas made up of a red, green, blue,
 * and alpha value.
 */
class Color final
{
public:
	/**
	 * Creates a color with the given values.
	 *
	 * No color values may be less than zero.
	 */
	inline Color(float red, float green, float blue, float alpha);

	/**
	 * Creates a color with the given values and an alpha of 1.0
	 *
	 * No color values may be less than zero.
	 */
	inline Color(float red, float green, float blue);

	inline Color(Color& other);

	inline Color operator=(Color& other);

	const float red;
	const float green;
	const float blue;
	const float alpha;

private:
	/**
	 * Validates that no color channels are less than zero.
	 */
	void inline validateChannels();
};

#endif