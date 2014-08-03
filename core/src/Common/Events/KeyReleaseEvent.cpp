#include "KeyReleaseEvent.h"
#include "InputCode.h"
KeyReleaseEvent::KeyReleaseEvent(KeyCode* keyCode)
{
	this->keyCode = keyCode;
}
