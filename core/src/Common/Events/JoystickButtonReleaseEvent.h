#ifndef Core_JoystickButtonReleaseEvent_h
#define Core_JoystickButtonReleaseEvent_h

#include "JoystickButtonEvent.h"

class JoystickButtonReleaseEvent : public JoystickButtonEvent
{
public:
    /**
     * @see JoystickButtonEvent::JoystickButtonEvent(unsigned int, unsigned int)
     */
    JoystickButtonReleaseEvent(unsigned int joystick, unsigned int button);

    JoystickButtonReleaseEvent(JoystickButtonReleaseEvent const &other);
private:
    // Private constructors to disallow access.
    JoystickButtonReleaseEvent operator=(JoystickButtonReleaseEvent other);
};

#endif
