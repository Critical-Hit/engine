#ifndef Core_KeyPressEvent_h
#define Core_KeyPressEvent_h

#include "KeyEvent.h"
enum KeyCode;

/**
 * Event fired when a keyboard key is pressed.
 */
class KeyPressEvent : public KeyEvent
{
public:
    /**
     * Event constructor.
     * @param keyCode Keyboard key which caused the event.
     */
    KeyPressEvent(KeyCode* keyCode);
private:
    // Private constructors to disallow access.
    KeyPressEvent(KeyPressEvent const &other);
    KeyPressEvent operator=(KeyPressEvent other);
};

#endif
