#ifndef Core_IInputManagerView_h
#define Core_IInputManagerView_h

#include <memory>

class KeyboardKeyPressEvent;
class KeyboardKeyReleaseEvent;
class MouseEvent;
class MouseButtonPressEvent;
class MouseButtonReleaseEvent;
enum class KeyboardKey;

namespace View
{
    class IInputManager
    {
    public:
        /**
         * True if the given KeyboardKey has at least one registered release event handler. False otherwise.
         */
        virtual bool IsRegisteredEventHandler(KeyboardKey key) = 0;

        /**
         * Distributes event to registered event handlers.
         * @param event event to distribute.
         */
        virtual void OnKeyboardKeyPress(KeyboardKeyPressEvent event) = 0;

        /**
         * Distributes event to registered event handlers.
         * @param event event to distribute.
         */
        virtual void OnKeyboardKeyRelease(KeyboardKeyReleaseEvent event) = 0;

        /**
         * Distributes event to registered event handlers.
         * @param event event to distribute.
         */
        virtual void OnMouseInput(MouseEvent event) = 0;

        /**
         * Distributes event to registered event handlers.
         * @param event event to distribute.
         */
        virtual void OnMouseButtonPress(MouseButtonPressEvent event) = 0;

        /**
         * Distributes event to registered event handlers.
         * @param event event to distribute.
         */
        virtual void OnMouseButtonRelease(MouseButtonReleaseEvent event) = 0;

        virtual ~IInputManager() {};
    };

    std::shared_ptr<IInputManager> CreateIInputManager();
}

#endif
