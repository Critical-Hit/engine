#ifndef Core_MouseButtonEvent_h
#define Core_MouseButtonEvent_h

#include "MouseEvent.h"
#include "InputCode.h"

/**
 * Input event fired when mouse button input occurs
 */
class MouseButtonEvent : public MouseEvent
{
public:
    /**
     * Event constructor.
     * @param absoluteX absolute x-coordinate of the mouse cursor 
     * @param absoluteY absolute y-coordiante of the mouse cursor
     * @param button button which caused the event
     */
    MouseButtonEvent(double absoluteX, double absoluteY, MouseCode button);
    
    /**
     * @return button which caused the event
     */
    MouseCode GetMouseButton();
protected:
    MouseCode button;
private:
    // Private constructors to disallow access.
    MouseButtonEvent(MouseButtonEvent const &other);
    MouseButtonEvent operator=(MouseButtonEvent other);
};

#endif
