#ifndef Core_MouseButtonEvent_h
#define Core_MouseButtonEvent_h

#include "MouseEvent.h"

enum class MouseButton;

/**
 * Input event fired when mouse button input occurs
 */
class MouseButtonEvent : public MouseEvent
{
public:
    /**
     * Event constructor.
     * @param absoluteX x-coordinate of the mouse cursor in relation to the left edge of the game window.
     * @param absoluteY y-coordiante of the mouse cursor in relation to the top edge of the game window.
     * @param button Mouse button which caused the event.
     */
    MouseButtonEvent(int absoluteX, int absoluteY, MouseButton button);
    
    MouseButtonEvent(MouseButtonEvent const &other);
    
    const MouseButton button;
private:
    // Private constructors to disallow access.
    MouseButtonEvent operator=(MouseButtonEvent other);
};

#endif
