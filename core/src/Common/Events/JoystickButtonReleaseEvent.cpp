#include "JoystickButtonReleaseEvent.h"

JoystickButtonReleaseEvent::JoystickButtonReleaseEvent(unsigned int joystick, unsigned int button) : JoystickButtonEvent(joystick, button)
{

}

JoystickButtonReleaseEvent::JoystickButtonReleaseEvent(JoystickButtonReleaseEvent const &other) : JoystickButtonReleaseEvent(other.joystick, other.button)
{

}
