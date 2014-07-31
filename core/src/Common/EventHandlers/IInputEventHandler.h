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
    void OnKeyboardKeyPress(KeyPressEvent*) {}

    /**
     * Event handler executed when a keyboard key is released.
     */
    void OnKeyboardKeyRelease(KeyReleaseEvent*) {}

    /**
     * Event handler executed when mouse input is received (i.e. every frame)
     */
    void OnMouseInput(MouseEvent*) {}

    /**
     * Event handler executed when a mouse button is pressed.
     */
    void OnMouseButtonPress(MouseButtonPressEvent*) {}

    /**
     * Event handler executed when a mouse button is released.
     */
    void OnMouseButtonRelease(MouseButtonReleaseEvent*) {}
};


#endif
