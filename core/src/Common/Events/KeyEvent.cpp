#include "KeyEvent.h"
#include "InputCode.h"

KeyCode KeyEvent::GetKeyCode()
{
    return *(this->keyCode);
}