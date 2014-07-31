#include "MouseButtonEvent.h"

MouseButtonEvent::MouseButtonEvent(double absoluteX, double absoluteY, MouseCode button) : MouseEvent(absoluteX, absoluteY)
{
    this->button = button;
}

MouseCode MouseButtonEvent::GetMouseButton()
{
    return this->button;
}
