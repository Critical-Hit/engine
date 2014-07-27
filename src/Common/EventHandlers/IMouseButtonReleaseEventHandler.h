#ifndef Core_IMouseButtonReleaseEventHandler_h
#define Core_IMouseButtonReleaseEventHandler_h

#include "IInputEventHandler.h"
#include "MouseButtonReleaseEvent.h"

/**
 *  Event handler interface for mouse button release input
 */
class IMouseButtonReleaseEventHandler : public IInputEventHandler
{
public:
    virtual ~IMouseButtonReleaseEventHandler() = 0;

    /**
     * Defines event handler behavior for mouse release events
     * @param event event to handle
     */
    virtual void OnMouseButtonRelease(MouseButtonReleaseEvent* event);
};

#endif
