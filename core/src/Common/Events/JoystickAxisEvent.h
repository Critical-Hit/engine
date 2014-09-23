#ifndef Core_JoystickAxisEvent_h
#define Core_JoystickAxisEvent_h

#include "JoystickEvent.h"
#include "JoystickAxis.h"

class JoystickAxisEvent : public JoystickEvent
{
public:
    /**
     * Event constuctor
     * @param joystick id of the joystick which fired this event.
     * @param axis axis which fired this event
     * @param position position of the joystick axis. -100.0 indicates the minimum position,
     * 0.0 indicates the center position and 100.0 indicates the maximum position.
     */
    JoystickAxisEvent(unsigned int joystick, JoystickAxis axis, float position);

    JoystickAxisEvent(JoystickAxisEvent const &other);

    const JoystickAxis axis;
    const float position;
private:
    // Private constructors to disallow access.
    JoystickAxisEvent operator=(JoystickAxisEvent other);
};

#endif
