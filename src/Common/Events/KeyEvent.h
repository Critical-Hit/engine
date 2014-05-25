#include "InputEvent.h"

class KeyEvent : InputEvent
{
    private:
        int keyCode;
    public:
        int GetKeyCode();
};
