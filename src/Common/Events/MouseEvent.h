#ifndef Core_MouseEvent_h
#define Core_MouseEvent_h

#include "InputEvent.h"

class MouseEvent : public InputEvent {
public:
    MouseEvent(double absoluteX, double absoluteY);

    /*
     * Returns the absolute x-coordinate of the cursor.
     */
    double GetAbsoluteX();

    /**
     * Returns the absolute y-coordinate of the cursor.
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
