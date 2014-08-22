#include "MouseEvent.h"

MouseEvent::MouseEvent (int x, int y)
{
    this->x = x;
    this->y = y;
}

int MouseEvent::GetX()
{
    return this->x;
}

int MouseEvent::GetY()
{
    return this->y;
}
