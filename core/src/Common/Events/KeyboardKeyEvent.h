#ifndef Core_KeyboardKeyEvent_h
#define Core_KeyboardKeyEvent_h

#include "InputEvent.h"

enum class KeyboardKey;

/**
 * Parent class for events related to keyboard keys.
 */
class KeyboardKeyEvent : public InputEvent
{
protected:
    // The keyboard key involved in this event.
    KeyboardKey* key;
public:
    /**
     * Get the keycode of the keyboard key which caused the event.
     * @return the keyboard key which caused the event
     */
    virtual KeyboardKey GetKeyboardKey();
};

#endif
