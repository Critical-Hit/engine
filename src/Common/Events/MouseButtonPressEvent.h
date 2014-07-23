#ifndef Core_MousePositionEvent_h
#define Core_MousePositionEvent_h

#include "MouseButtonEvent.h"
#include "InputCode.h"

class MouseButtonPressEvent : public MouseButtonEvent
{
public:
    MouseButtonPressEvent(int absoluteX, int absoluteY, MouseCode button);
private:
    // Private constructors to disallow access.
    MouseButtonPressEvent(MouseButtonPressEvent const &other);
    MouseButtonPressEvent operator=(MouseButtonPressEvent other);
};

#endif
