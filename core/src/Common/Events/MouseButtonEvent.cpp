#include "MouseButtonEvent.h"

MouseButtonEvent::MouseButtonEvent(int absoluteX, int absoluteY, MouseButton button) : MouseEvent(absoluteX, absoluteY)
{
    this->button = button;
}

MouseButton MouseButtonEvent::GetMouseButton()
{
    return this->button;
}
