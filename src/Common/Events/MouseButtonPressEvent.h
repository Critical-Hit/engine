#ifndef Core_MouseButtonPressEvent_h
#define Core_MouseButtonPressEvent_h

#include "MouseButtonEvent.h"

/**
 * Input event fired when a mouse button is pressed
 */
class MouseButtonPressEvent : public MouseButtonEvent
{
public:
    using MouseButtonEvent::MouseButtonEvent;
private:
    // Private constructors to disallow access.
    MouseButtonPressEvent(MouseButtonPressEvent const &other);
    MouseButtonPressEvent operator=(MouseButtonPressEvent other);
};

#endif
