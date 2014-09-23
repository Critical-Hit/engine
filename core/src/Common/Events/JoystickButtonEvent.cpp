#include "JoystickButtonEvent.h"

JoystickButtonEvent::JoystickButtonEvent(unsigned int joystick, unsigned int button) : JoystickEvent(joystick), button(button)
{

}

JoystickButtonEvent::JoystickButtonEvent(JoystickButtonEvent const &other) : JoystickButtonEvent(other.joystick, other.button)
{

}
