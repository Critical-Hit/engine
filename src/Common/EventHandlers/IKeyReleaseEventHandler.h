#ifndef Core_IKeyReleaseEventHandler_h
#define Core_IKeyReleaseEventHandler_h

#include "IKeyEventHandler.h"
class KeyReleaseEvent;

/**
 * Interface for handling KeyReleaseEvents.
 */
class IKeyReleaseEventHandler : IKeyEventHandler
{
public:
    virtual ~IKeyReleaseEventHandler() {};
    virtual void OnKeyReleaseEvent(KeyReleaseEvent* event) = 0;
};

#endif
