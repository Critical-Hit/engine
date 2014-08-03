#include "MouseButtonEvent.h"

MouseButtonEvent::MouseButtonEvent(int absoluteX, int absoluteY, MouseCode button) : MouseEvent(absoluteX, absoluteY)
{
    this->button = button;
}

MouseCode MouseButtonEvent::GetMouseButton()
{
    return this->button;
}
