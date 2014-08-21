#ifndef Core_IInputEventHandler_h
#define Core_IInputEventHandler_h

#include "IEventHandler.h"

class KeyboardKeyPressEvent;
class KeyboardKeyReleaseEvent;
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
    virtual void OnKeyboardKeyPress(KeyboardKeyPressEvent*) {}

    /**
     * Event handler executed when a keyboard key is released.
     */
    virtual void OnKeyboardKeyRelease(KeyboardKeyReleaseEvent*) {}

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
