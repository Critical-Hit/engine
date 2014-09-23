#ifndef Core_JoystickButtonEvent_h
#define Core_JoystickButtonEvent_h

#include "JoystickEvent.h"

class JoystickButtonEvent : public JoystickEvent
{
public:
    /**
     * Event constructor.
     * @param joystick id of the joystick that fired this event
     * @param button id of the button that fired this event
     */
    JoystickButtonEvent(unsigned int joystick, unsigned int button);

    JoystickButtonEvent(JoystickButtonEvent const &other);

    const unsigned int button;
private:
    // Private constructors to disallow access.
    JoystickButtonEvent operator=(JoystickButtonEvent other);
};

#endif
