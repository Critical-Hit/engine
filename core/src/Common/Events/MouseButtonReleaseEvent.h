#ifndef Core_MouseButtonReleaseEvent_h
#define Core_MouseButtonReleaseEvent_h

#include "MouseButtonEvent.h"

enum class MouseButton;

/**
 * Input event fired when a mouse button is released
 */
class MouseButtonReleaseEvent : public MouseButtonEvent
{
public:
    /**
     * @see MouseButtonEvent::MouseButtonEvent(int, int, MouseButton)
     */
    MouseButtonReleaseEvent(int x, int y, MouseButton button);
private:
    // Private constructors to disallow access.
    MouseButtonReleaseEvent(MouseButtonReleaseEvent const &other);
    MouseButtonReleaseEvent operator=(MouseButtonReleaseEvent other);
};

#endif
