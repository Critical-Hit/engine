#include "KeyPressEvent.h"
#include "InputCode.h"
KeyPressEvent::KeyPressEvent(KeyCode* keyCode)
{
	this->keyCode = keyCode;
}
