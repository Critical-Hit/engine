#ifndef Core_KeyboardKeyboardKeyReleaseEvent_h
#define Core_KeyboardKeyboardKeyReleaseEvent_h

#include "KeyboardKeyEvent.h"

enum class KeyboardKey;

/**
 * Event fired when a keyboard key is released.
 */
class KeyboardKeyReleaseEvent : public KeyboardKeyEvent
{
public:
    /**
     * Event constructor.
     * @param key Keyboard key which caused the event.
     */
    KeyboardKeyReleaseEvent(KeyboardKey key);
    
    KeyboardKeyReleaseEvent(KeyboardKeyReleaseEvent const &other);
private:
    // Private constructors to disallow access.
    KeyboardKeyReleaseEvent operator=(KeyboardKeyReleaseEvent other);
};

#endif
