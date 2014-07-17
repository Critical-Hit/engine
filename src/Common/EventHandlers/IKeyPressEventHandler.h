#ifndef Core_IKeyPressEventHandler_h
#define Core_IKeyPressEventHandler_h

#include "IKeyEventHandler.h"
class KeyPressEvent;
class IKeyPressEventHandler : IKeyEventHandler
{
    public:
        virtual void OnKeyPressEvent(KeyPressEvent* event) = 0;
};

#endif
