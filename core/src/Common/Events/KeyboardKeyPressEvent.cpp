#include "KeyboardKeyPressEvent.h"

KeyboardKeyPressEvent::KeyboardKeyPressEvent(KeyboardKey key) : KeyboardKeyEvent(key)
{

}

KeyboardKeyPressEvent::KeyboardKeyPressEvent(KeyboardKeyPressEvent const &other) : KeyboardKeyEvent(other.key)
{

}
