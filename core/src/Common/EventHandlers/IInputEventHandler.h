#ifndef Core_IInputEventHandler_h
#define Core_IInputEventHandler_h

#include "IEventHandler.h"

/**
 * Marker interface for input event handler interfaces.
 */
class IInputEventHandler : public IEventHandler
{
public:
    virtual ~IInputEventHandler() {};
};


#endif
