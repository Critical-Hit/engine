#ifndef Core_IKeyEventHandler_h
#define Core_IKeyEventHandler_h

#include "IInputEventHandler.h"

/**
 * Marker interface for keyboard key event handler interfaces.
 */
class IKeyEventHandler : public IInputEventHandler
{
public:
    virtual ~IKeyEventHandler() {};
};

#endif
