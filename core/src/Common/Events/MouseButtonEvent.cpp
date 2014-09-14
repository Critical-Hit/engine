#include "MouseButtonEvent.h"

MouseButtonEvent::MouseButtonEvent(int x, int y, MouseButton button) : MouseEvent(x, y), button(button)
{

}

MouseButtonEvent::MouseButtonEvent(MouseButtonEvent const &other) : MouseEvent(other.x, other.y), button(other.button)
{

}

