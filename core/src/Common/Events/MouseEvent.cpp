#include "MouseEvent.h"

MouseEvent::MouseEvent (int x, int y)
{
    this->x = x;
    this->y = y;
}

int MouseEvent::GetXPosition()
{
    return this->x;
}

int MouseEvent::GetYPosition()
{
    return this->y;
}
