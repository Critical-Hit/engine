#ifndef Common_Events_KeyReleaseEvent_H
#define Common_Events_KeyReleaseEvent_H

#include "KeyEvent.h"
#include "InputCode.h"
class KeyReleaseEvent : public KeyEvent
{
	public:
		KeyReleaseEvent(KeyCode* KeyCode);
};

#endif
