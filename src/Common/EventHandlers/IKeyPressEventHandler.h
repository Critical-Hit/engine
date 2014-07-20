#ifndef Core_IKeyPressEventHandler_h
#define Core_IKeyPressEventHandler_h

#include "IKeyEventHandler.h"
class KeyPressEvent;

/**
 * Interface for handling KeyPressEvents.
 */
class IKeyPressEventHandler : IKeyEventHandler
{
public:
    virtual ~IKeyPressEventHandler() {};
    virtual void OnKeyPressEvent(KeyPressEvent* event) = 0;
};

#endif
