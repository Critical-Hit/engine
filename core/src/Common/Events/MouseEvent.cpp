#include "MouseEvent.h"

MouseEvent::MouseEvent (int x, int y) : x(x), y(y)
{

}

MouseEvent::MouseEvent(MouseEvent const &other) : MouseEvent(other.x, other.y)
{

}
