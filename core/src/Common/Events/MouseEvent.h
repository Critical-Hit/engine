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
     * @param absoluteX absolute x-coordinate of the mouse cursor
     * @param absoluteY absolute y-coordinate of the mouse cursor
     */
    MouseEvent(int absoluteX, int absoluteY);

    /*
     * @return absolute x-coordinate of the cursor.
     */
    int GetAbsoluteX();

    /**
     * @return absolute y-coordinate of the cursor.
     */
    int GetAbsoluteY();
protected:
    int absoluteX;
    int absoluteY;
private:
    // Private constructors to disallow access.
    MouseEvent(MouseEvent const &other);
    MouseEvent operator=(MouseEvent other);
};

#endif
