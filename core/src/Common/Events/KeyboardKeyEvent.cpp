#include "KeyboardKeyEvent.h"
#include "KeyboardKey.h"

KeyboardKey KeyboardKeyEvent::GetKeyboardKey()
{
    return *(this->key);
}
