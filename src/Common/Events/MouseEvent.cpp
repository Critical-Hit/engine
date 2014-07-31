#include "MouseEvent.h"

MouseEvent::MouseEvent (double absoluteX, double absoluteY)
{
    this->absoluteX = absoluteX;
    this->absoluteY = absoluteY;
}

double MouseEvent::GetAbsoluteX()
{
    return this->absoluteX;
}

double MouseEvent::GetAbsoluteY()
{
    return this->absoluteY;
}
