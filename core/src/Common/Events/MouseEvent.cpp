#include "MouseEvent.h"

MouseEvent::MouseEvent (int absoluteX, int absoluteY)
{
    this->absoluteX = absoluteX;
    this->absoluteY = absoluteY;
}

int MouseEvent::GetAbsoluteX()
{
    return this->absoluteX;
}

int MouseEvent::GetAbsoluteY()
{
    return this->absoluteY;
}
