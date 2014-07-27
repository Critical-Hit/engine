#ifndef Core_MouseButtonReleaseEvent_h
#define Core_MouseButtonReleaseEvent_h

#include "MouseButtonEvent.h"

/**
 * Input event fired when a mouse button is released
 */
class MouseButtonReleaseEvent : public MouseButtonEvent
{
public:
    using MouseButtonEvent::MouseButtonEvent;
private:
    // Private constructors to disallow access.
    MouseButtonReleaseEvent(MouseButtonReleaseEvent const &other);
    MouseButtonReleaseEvent operator=(MouseButtonReleaseEvent other);
};

#endif
