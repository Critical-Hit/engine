#ifndef Core_Sprite_h
#define Core_Sprite_h

#include <assert.h>
#include "Color.h"
#include "TextureId.h"

// Enum representing the two different ways sprites can render
enum class SpriteRenderMode
{
    SolidColor,
    Textured
};

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
     * Basic constructor for a colored sprite
     *
     * Width and height must both be greater than zero.
     */
    Sprite(float x, float y, float width, float height, Color color);

    /**
     * Basic constructor for a colored sprite, setting x and y to 0.
     *
     * Width and height must both be greater than zero.
     */
    Sprite(float width, float height, Color color);

    /**
    * Basic constructor for a textured sprite
    *
    * Width and height must both be greater than zero.
    */
    Sprite(float x, float y, float width, float height, Common::TextureId textureId);

    /**
    * Basic constructor for a textured sprite, setting x and y to 0.
    *
    * Width and height must both be greater than zero.
    */
    Sprite(float width, float height, Common::TextureId color);

    /**
     * Moves the sprite to the given location
     */
    void MoveTo(float x, float y);

    /**
     * Moves the sprite by the given amount in the x and y
     * direction
     */
    void MoveBy(float dx, float dy);

    /**
     * Changes the width to the given value
     *
     * Width must be greater than zero.
     */
    void ChangeWidth(float width);

    /**
     * Changes the height to the given value
     *
     * Height must be greater than zero.
     */
    void ChangeHeight(float height);

    /**
     * Changes the dimensions of the sprite to the given value
     *
     * Width and height must both be greater than zero.
     */
    void ChangeDimensions(float width, float height);

    /**
     * Sets the color of the sprite; removing the texture
     * if the sprite was previously textured.
     */
    void SetColor(Color color);

    /**
     * Sets the texture to use for the sprite; removes color if
     * the sprite was previously colored.
     */
    void SetTextureId(Common::TextureId textureId);

    /**
     * Obtains x
     */
    float GetX();

    /**
     * Obtains y
     */
    float GetY();

    /**
     * Obtains width
     */
    float GetWidth();

    /**
     * Obtains height
     */
    float GetHeight();

    /**
     * Obtains the sprite's color
     */
    Color GetColor();

    /**
     * Obtains the sprite's texture id
     */
    Common::TextureId GetTextureId();

    /**
     * Obtains the sprites render mode
     */
    SpriteRenderMode GetRenderMode();

    /**
     * Puts OpenGL vertex information into the given array.
     * 
     * DO NOT CALL THIS METHOD IF THERE IS NOT SPACE FOR 16 ADDITIONAL
     * VALUES WITHIN THE ARRAY.
     *
     * Typically this function isn't needed outside the game engine's
     * core graphics system, and thus it shouldn't be needed by users.
     */
    void PutGLVertexInfo(float* vertexBuffer);

    /**
     * Puts OpenGL color information into the given array.
     *
     * DO NOT CALL THIS METHOD IF THERE IS NOT SPACE FOR 12 ADDITIONAL
     * VALUES WITHIN THE ARRAY.
     *
     * Typically this function isn't needed outside the game engine's
     * core graphics system, and thus it shouldn't be needed by users.
     */
    void PutGLColorInfo(float* colorBuffer);

    /**
     * Puts OpenGL index information into the given array.  It 
     *
     * DO NOT CALL THIS METHOD IF THERE IS NOT SPACE FOR 6 ADDITIONAL
     * VALUES WITHIN THE ARRAY.
     *
     * Typically this function isn't needed outside the game engine's
     * core graphics system, and thus it shouldn't be needed by users.
     */
    void PutGLIndexInfo(unsigned short* indexBuffer, unsigned short dataStartIndex);

protected:
    float x;
    float y;
    float width;
    float height;
    Color color;
    Common::TextureId textureId;

    /**
     * Validates that width and height are greater than zero.
     */
    void validateDimensions();

private:
    static const int vertexCount = 6;
    Sprite operator=(Sprite& other);
    Sprite(Sprite& other);
    SpriteRenderMode renderMode;
};

#endif
