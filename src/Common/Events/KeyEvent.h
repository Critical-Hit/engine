#ifndef Core_KeyEvent_h
#define Core_KeyEvent_h

#include "InputEvent.h"
#include "InputCode.h"

/**
 * Parent class for events related to keyboard keys.
 */
 class KeyEvent : public InputEvent
 {
 protected:
	// The keycode of the keyboard key involved in this event.
 	KeyCode* keyCode;
 public:
	/**
	 * Get the keycode of the keyboard key involved in this event.
	 */
	virtual KeyCode GetKeyCode();
};

#endif
