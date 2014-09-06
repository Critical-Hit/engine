#ifndef Core_MouseEvent_h
#define Core_MouseEvent_h

#include "InputEvent.h"

/**
 * Input event fired when mouse input occurs
 */
class MouseEvent : public InputEvent {
public:
    /**
     * Event constructor
     * @param x x-coordinate of the mouse cursor in relation to the left edge of the game window
     * @param y y-coordinate of the mouse cursor in relation to the top edge of the game window
     */
    MouseEvent(int x, int y);

    /**
     * Get the horizontal position of the mouse cursor
     * @return x-coordinate of the cursor in relation to the left edge of the game window
     */
    int GetX();

    /**
     * Get the vertical position of the mouse cursor
     * @return y-coordinate of the cursor in relation to the top edge of the game window
     */
    int GetY();
protected:
    int x;
    int y;
private:
    // Private constructors to disallow access.
    MouseEvent(MouseEvent const &other);
    MouseEvent operator=(MouseEvent other);
};

#endif
