#ifndef Core_JoystickEvent_h
#define Core_JoystickEvent_h

#include "InputEvent.h"

/**
 * Base class for input events.
 */
class JoystickEvent : public InputEvent {
public:
    /**
     * Event constructor
     * @param joystick id of the joystick that fired this event
     */
    JoystickEvent(unsigned int joystick);

    JoystickEvent(JoystickEvent const &other);

    const unsigned int joystick;
private:
    // Private constructors to disallow access.
    JoystickEvent operator=(JoystickEvent other);
};

#endif
