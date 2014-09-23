#include "JoystickButtonPressEvent.h"

JoystickButtonPressEvent::JoystickButtonPressEvent(unsigned int joystick, unsigned int button) : JoystickButtonEvent(joystick, button)
{

}

JoystickButtonPressEvent::JoystickButtonPressEvent(JoystickButtonPressEvent const &other) : JoystickButtonPressEvent(other.joystick, other.button)
{

}
