#ifndef Core_KeyEvent_h
#define Core_KeyEvent_h

#include "KeyEvent.h"
enum KeyCode;
class KeyPressEvent : public KeyEvent
{
    public:
        KeyPressEvent(KeyCode* keyCode);
};

#endif
