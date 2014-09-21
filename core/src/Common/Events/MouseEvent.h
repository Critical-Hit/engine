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

    MouseEvent(MouseEvent const &other);
    
    const int x;
    const int y;
private:
    // Private constructors to disallow access.
    MouseEvent operator=(MouseEvent other);
};

#endif
