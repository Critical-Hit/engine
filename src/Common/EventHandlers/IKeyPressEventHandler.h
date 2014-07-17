#ifndef Core_IKeyPressEventHandler_h
#define Core_IKeyPressEventHandler_h

#include "IKeyEventHandler.h"
class KeyPressEvent;
class IKeyPressEventHandler : IKeyEventHandler
{
    public:
        void OnKeyPressEvent(KeyPressEvent* event);
};

#endif
