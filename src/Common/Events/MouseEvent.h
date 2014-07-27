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
    MouseEvent(double absoluteX, double absoluteY);

    /*
     * @return absolute x-coordinate of the cursor.
     */
    double GetAbsoluteX();

    /**
     * @return absolute y-coordinate of the cursor.
     */
    double GetAbsoluteY();
protected:
    double absoluteX;
    double absoluteY;
private:
    // Private constructors to disallow access.
    MouseEvent(MouseEvent const &other);
    MouseEvent operator=(MouseEvent other);
};

#endif
