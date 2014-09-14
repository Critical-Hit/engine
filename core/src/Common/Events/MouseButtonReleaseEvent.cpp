#include "MouseButtonReleaseEvent.h"

MouseButtonReleaseEvent::MouseButtonReleaseEvent(int x, int y, MouseButton button) : MouseButtonEvent(x, y, button)
{

}

MouseButtonReleaseEvent::MouseButtonReleaseEvent(MouseButtonReleaseEvent const &other) : MouseButtonReleaseEvent(other.x, other.y, other.button)
{

}
