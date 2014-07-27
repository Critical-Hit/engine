#ifndef Core_Camera_h
#define Core_Camera_h

class string;

/**
 * A class that is used to represent the camera,
 * or the viewport the window is.  Users can define
 * the coordinate system of the game world however
 * they like, and they simply need to set up the
 * camera appropriately.
 *
 * Cameras cannot be rotated, so they are always
 * axis-aligned.
 *
 * When referenced, x and y coordinates are always the
 * center of the camera.
 * 
 * By default, the camera assumes +y points towards
 * the top of the screen.
 */
class Camera final
{
public:
	/**
	 * Creates a camera centered at 0, 0 with a width
	 * and height of 2.
	 */
	Camera();
	
	/**
	 * Creats a camera with the given coordinates and
	 * dimensions.
	 */
	Camera(float x, float y, float width, float height);

	/**
	 * Moves the camera's center to the given coordinates.
	 */
	void MoveTo(float x, float y);
	
	/**
	 * Moves the camera by the given amount.
	 */
	void MoveBy(float dx, float dy);

	/**
	 * Sets the dimensions used by the camera
	 */
	void SetDimensions(float width, float height);

	/**
	 * Obtains the x value for the center of the camera
	 */
	float getX();

	/**
	 * Obtains the y value for the center of the camera
	 */
	float getY();

	/**
	 * Obtains the width of the camera's viewing area
	 */
	float getWidth();

	/**
	 * Obtains the height of the camera's viewing area
	 */
	float getHeight();

	/**
	 * Obtains the coordinate for the left edge of the camera
	 */
	float GetLeft();

	/**
	* Obtains the coordinate for the right edge of the camera
	*/
	float GetRight();

	/**
	* Obtains the coordinate for the top edge of the camera
	*/
	float GetTop();

	/**
	* Obtains the coordinate for the bottom edge of the camera
	*/
	float GetBottom();

	/**
	 * Obtains a string with the x, y, width, and height of the
	 * camera.
	 */
	std::string ToString();

	/**
	* Obtains a string with the left, right width, and height
	* of the camera.
	*/
	std::string ToStringLRTB();

	/**
	 * Basic destructor.
	 */
	~Camera();

private:
	Camera(Camera& other);
	Camera operator=(Camera& other);
	float x;
	float y;
	float width;
	float halfWidth;
	float height;
	float halfHeight;
	bool reverseY;

	/**
	* Sets whether the camera's y coordinates are reversed.
	*
	* True: -y points towards the top of the screen.
	* False: +y points towards the top of the screen.
	*
	* Moved to private until a related graphics bug can
	* be solved.
	*/
	void SetReverseY(bool reverseY);
};

#endif