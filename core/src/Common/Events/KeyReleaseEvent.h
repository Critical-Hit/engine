#ifndef Core_KeyReleaseEvent_h
#define Core_KeyReleaseEvent_h

#include "KeyEvent.h"
#include "InputCode.h"

/**
 * Event fired when a keyboard key is released.
 */
class KeyReleaseEvent : public KeyEvent
{
public:
    /**
     * Event constructor.
     * @param keyCode Keyboard key which caused the event.
     */
    KeyReleaseEvent(KeyCode* keyCode);
private:
    // Private constructors to disallow access.
    KeyReleaseEvent(KeyReleaseEvent const &other);
    KeyReleaseEvent operator=(KeyReleaseEvent other);
};

#endif
