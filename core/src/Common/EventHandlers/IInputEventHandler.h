#ifndef Core_IInputEventHandler_h
#define Core_IInputEventHandler_h

#include "IEventHandler.h"

class KeyPressEvent;
class KeyReleaseEvent;
class MouseEvent;
class MouseButtonPressEvent;
class MouseButtonReleaseEvent;
/**
 * Interface for handling events related to input.
 */
class IInputEventHandler : public IEventHandler
{
public:
    virtual ~IInputEventHandler() {};

    /**
     * Event handler executed when a keyboard key is pressed.
     */
    virtual void OnKeyboardKeyPress(KeyPressEvent*) {}

    /**
     * Event handler executed when a keyboard key is released.
     */
    virtual void OnKeyboardKeyRelease(KeyReleaseEvent*) {}

    /**
     * Event handler executed when mouse input is received (i.e. every frame)
     */
    virtual void OnMouseInput(MouseEvent*) {}

    /**
     * Event handler executed when a mouse button is pressed.
     */
    virtual void OnMouseButtonPress(MouseButtonPressEvent*) {}

    /**
     * Event handler executed when a mouse button is released.
     */
    virtual void OnMouseButtonRelease(MouseButtonReleaseEvent*) {}
};


#endif
