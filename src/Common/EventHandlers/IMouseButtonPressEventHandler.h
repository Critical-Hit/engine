#ifndef Core_IMouseButtonPressEventHandler_h
#define Core_IMouseButtonPressEventHandler_h

#include "IInputEventHandler.h"
#include "MouseButtonPressEvent.h"

/**
 * Event handler interface for mouse button press input
 */
class IMouseButtonPressEventHandler : public IInputEventHandler
{
public:
    virtual ~IMouseButtonPressEventHandler() = 0;

    /**
     * Defines event handler behavior for mouse press events
     * @param event event to handle
     */
    virtual void OnMouseButtonPress(MouseButtonPressEvent* event);
};

#endif
