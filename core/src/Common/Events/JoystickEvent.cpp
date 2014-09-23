#include "JoystickEvent.h"

JoystickEvent::JoystickEvent(unsigned int joystick) : joystick(joystick)
{

}

JoystickEvent::JoystickEvent(JoystickEvent const &other) : JoystickEvent(other.joystick)
{

}
