#include "JoystickAxisEvent.h"

JoystickAxisEvent::JoystickAxisEvent(unsigned int joystick, JoystickAxis axis, float position) :
    JoystickEvent(joystick), axis(axis), position(position)
{

}

JoystickAxisEvent::JoystickAxisEvent(JoystickAxisEvent const &other) :
    JoystickAxisEvent(other.joystick, other.axis, other.position)
{

}
