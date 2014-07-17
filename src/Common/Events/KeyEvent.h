#ifndef Common_Events_KeyEvent_H
#define Common_Events_KeyEvent_H

#include "InputEvent.h"
#include "InputCode.h"

class KeyEvent : public InputEvent
{
    protected:
        KeyCode* keyCode;
    public:
        virtual KeyCode GetKeyCode();
};

#endif
