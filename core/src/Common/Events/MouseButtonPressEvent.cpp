#include "MouseButtonPressEvent.h"

MouseButtonPressEvent::MouseButtonPressEvent(int x, int y, MouseButton button) : MouseButtonEvent(x, y, button)
{

}

MouseButtonPressEvent::MouseButtonPressEvent(MouseButtonPressEvent const &other) : MouseButtonPressEvent(other.x, other.y, other.button)
{

}
