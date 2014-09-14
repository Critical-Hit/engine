#include "KeyboardKeyEvent.h"
#include "KeyboardKey.h"

KeyboardKeyEvent::KeyboardKeyEvent(KeyboardKey key) : key(key) 
{
}

KeyboardKeyEvent::KeyboardKeyEvent(KeyboardKeyEvent const &other) : key(other.key)
{

}

