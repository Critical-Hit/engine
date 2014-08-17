#ifndef Core_MouseButtonPressEvent_h
#define Core_MouseButtonPressEvent_h

#include "MouseButtonEvent.h"

/**
 * Input event fired when a mouse button is pressed
 */
class MouseButtonPressEvent : public MouseButtonEvent
{
public:
    /**
     * @see MouseButtonEvent::MouseButtonEvent(int, int, MouseCode)
     */
    MouseButtonPressEvent(int absoluteX, int absoluteY, MouseCode mouseCode);
private:
    // Private constructors to disallow access.
    MouseButtonPressEvent(MouseButtonPressEvent const &other);
    MouseButtonPressEvent operator=(MouseButtonPressEvent other);
};

#endif
