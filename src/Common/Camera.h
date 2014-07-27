#ifndef Core_Camera_h
#define Core_Camera_h

/**
 * A class that is used to represent the camera,
 * or the viewport the window is.  Users can define
 * the coordinate system of the game world however
 * they like, and they simply need to set up the
 * camera appropriately.
 *
 * Cameras cannot be rotated, so they are always
 * axis-aligned.
 */
class Camera
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
	 * Basic destructor.
	 */
	~Camera();

private:
	Camera(Camera& other);
	Camera operator=(Camera& other);
	float x;
	float y;
	float width;
	float height;
};

#endif