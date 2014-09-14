#ifndef Core_KeyboardKeyEvent_h
#define Core_KeyboardKeyEvent_h

#include "InputEvent.h"

enum class KeyboardKey;

/**
 * Parent class for events related to keyboard keys.
 */
class KeyboardKeyEvent : public InputEvent
{
public:
    KeyboardKeyEvent(KeyboardKey);

    KeyboardKeyEvent(KeyboardKeyEvent const &other);
    
    const KeyboardKey key;
private:
    KeyboardKeyEvent operator=(KeyboardKeyEvent other);
};

#endif
