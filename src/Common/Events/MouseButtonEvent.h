#ifndef Core_MouseButtonEvent_h
#define Core_MouseButtonEvent_h

#include "MouseEvent.h"
#include "InputCode.h"

class MouseButtonEvent : public MouseEvent
{
public:
    MouseButtonEvent(int absoluteX, int absoluteY, MouseCode button);

    MouseCode GetMouseButton();
protected:
    MouseCode button;
private:
    // Private constructors to disallow access.
    MouseButtonEvent(MouseButtonEvent const &other);
    MouseButtonEvent operator=(MouseButtonEvent other);
};

#endif
