#ifndef Core_JoystickButtonPressEvent_h
#define Core_JoystickButtonPressEvent_h

#include "JoystickButtonEvent.h"

class JoystickButtonPressEvent : public JoystickButtonEvent
{
public:
    /**
     * @see JoystickButtonEvent::JoystickButtonEvent(unsigned int, unsigned int)
     */
    JoystickButtonPressEvent(unsigned int joystick, unsigned int button);

    JoystickButtonPressEvent(JoystickButtonPressEvent const &other);
private:
    // Private constructors to disallow access.
    JoystickButtonPressEvent operator=(JoystickButtonPressEvent other);
};

#endif
