#ifndef Core_KeyboardKeyPressEvent_h
#define Core_KeyboardKeyPressEvent_h

#include "KeyboardKeyEvent.h"

enum class KeyboardKey;

/**
 * Event fired when a keyboard key is pressed.
 */
class KeyboardKeyPressEvent : public KeyboardKeyEvent
{
public:
    /**
     * Event constructor.
     * @param key Keyboard key which caused the event.
     */
    KeyboardKeyPressEvent(KeyboardKey key);
    
    KeyboardKeyPressEvent(KeyboardKeyPressEvent const &other);
private:
    // Private constructors to disallow access.
    KeyboardKeyPressEvent operator=(KeyboardKeyPressEvent other);
};

#endif
