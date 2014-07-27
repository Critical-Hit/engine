#ifndef Core_IMouseEventHandler_h
#define Core_IMouseEventHandler_h

#include "IInputEventHandler.h"
#include "MouseEvent.h"

/**
 * Event handler interface for mouse input
 */
class IMouseEventHandler : public IInputEventHandler
{
public:
    virtual ~IMouseEventHandler() = 0;

    /**
     * Defines event handler behavior for mouse events
     * @param event event to handle
     */
    virtual void OnMouseEvent(MouseEvent* event);
};

#endif
