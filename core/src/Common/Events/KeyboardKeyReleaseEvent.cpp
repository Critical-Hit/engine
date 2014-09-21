#include "KeyboardKeyReleaseEvent.h"

KeyboardKeyReleaseEvent::KeyboardKeyReleaseEvent(KeyboardKey key) : KeyboardKeyEvent(key)
{

}

KeyboardKeyReleaseEvent::KeyboardKeyReleaseEvent(KeyboardKeyReleaseEvent const &other) : KeyboardKeyEvent(other.key)
{

}
