#ifndef Core_IInputManager_h
#define Core_IInputManager_h

#include <memory>

class InputView;
class KeyboardKeyPressEvent;
class KeyboardKeyReleaseEvent;
class MouseEvent;
class MouseButtonPressEvent;
class MouseButtonReleaseEvent;
enum class KeyboardKey;
enum class MouseButton;
enum class MouseInputMode;
enum class InputState;
namespace Model
{
    class IInputManager
    {
    public:
        // How does this work if the object that owns the function is destroyed?
        typedef std::function<void (MouseEvent)> MouseMotionHandler;
        typedef std::function<void (MouseButtonPressEvent)> MouseButtonPressHandler;
        typedef std::function<void (MouseButtonReleaseEvent)> MouseButtonReleaseHandler;
        typedef std::function<void (KeyboardKeyPressEvent)> KeyboardKeyPressHandler;
        typedef std::function<void (KeyboardKeyReleaseEvent)> KeyboardKeyReleaseHandler;

        /**
         * Associate an InputView with this InputManager. The InputView specified here will be used to poll input state on demand. 
         * Only one InputView may be associated with an InputManager at a time.
         * @param inputView InputView to associated with this InputManager
         */
        void SetView(std::shared_ptr<InputView> inputView);

        /**
         * Set the mouse cursor behavior.
         * @param mode one of the following:
         * * MouseInputMode::SHOW - Draw the operating system cursor.
         * * MouseInputMode::HIDE - Hide the operating system cursor.
         * * MouseInputMode::HIDE_AND_LOCK - Hide the operating system cursor and lock the cursor to the game window.
         */

        virtual void SetMouseInputMode(MouseInputMode mode) = 0;
        /**
         * Get the current mouse cursor behavior.
         * @return one of the following:
         * * MouseInputMode::SHOW - The operating system cursor is being drawn.
         * * MouseInputMode::HIDE - The operating system cursor is hidden.
         * * MouseInputMode::HIDE_AND_LOCK - The operating system cursor is hidden and the cursor is locked to the game window.
         */
        virtual MouseInputMode GetMouseInputMode() = 0;

        /**
         * Register a function to handle mouse input.
         * @param handler A function which will receive and handler MouseEvents when the mouse cursor is moved.
         * Any existing handler will be overwritten.
         */
        virtual void RegisterMouseMotionHandler(MouseMotionHandler handler) = 0;

        /**
         * Register a function to handle mouse button presses.
         * @param button A mouse button.
         * @param handler A function which will receive and handle MouseButtonPressEvents when the specified mouse button is pressed.
         * Any existing button press handler for the specified mouse button will be overwritten.
         */
        virtual void RegisterMouseButtonPressHandler(MouseButton button, MouseButtonPressHandler handler) = 0;

        /**
         * Register a function to handle mouse button releases.
         * @param button A mouse button.
         * @param handler A function which will receive and handle MouseButtonReleaseEvents when the specified mouse button is released.
         * Any existing button released handler for the specified mouse button will be overwritten.
         */
        virtual void RegisterMouseButtonReleaseHandler(MouseButton button, MouseButtonReleaseHandler handler) = 0;

        /**
         * Register a function to handle keyboard key presses.
         * @param key A keyboard key.
         * @param handler A function which will receive and handle KeyboardKeyPressEvents when the specified key is pressed.
         * Any existing key press handler for the specified key will be overwritten.
         */
        virtual void RegisterKeyboardKeyPressHandler(KeyboardKey key, KeyboardKeyPressHandler handler) = 0;

        /**
         * Register a function to handle keyboard key presses.
         * @param key A keyboard key.
         * @param handler A function which will receive and handle KeyboardKeyPressEvents when the specified key is released.
         * Any existing key release handler for the specified key will be overwritten.
         */
        virtual void RegisterKeyboardKeyReleaseHandler(KeyboardKey key, KeyboardKeyReleaseHandler handler) = 0;

        /**
         * Remove any existing mouse input handler.
         */
        virtual void DeregisterMouseMotionHandler() = 0;   

        /**
         * Remove any existing mouse button press handler for the specified button.
         * @param button A mouse button.
         */
        virtual void DeregisterMouseButtonPressHandler(MouseButton button) = 0;

        /**
         * Remove any existing mouse button release handler for the specified button.
         * @param button A mouse button.
         */
        virtual void DeregisterMouseButtonReleaseHandler(MouseButton button) = 0;

        /**
         * Remove any existing keyboard key press handler for the specified button.
         * @param key A keyboard key.
         */
        virtual void DeregisterKeyboardKeyPressHandler(KeyboardKey key) = 0;

        virtual void DeregisterKeyboardKeyReleaseHandler(KeyboardKey key) = 0;
        /**
         * Poll the current state of a key.
         * @param key The keyboard key to poll.
         * @return the current state of the keyboard key.
         * If an invalid key code was passed, KeyState::Invalid is returned.
         */
        virtual InputState GetKeyState(KeyboardKey key) = 0;

        /**
         * Poll the current state of a mouse button.
         * @param button The mouse button to poll.
         * @return the current state of the mouse button
         */
        virtual InputState GetMouseButtonState(MouseButton button) = 0;

        /**
         * Poll the horizontal coordinate of the mouse cursor. 
         * @return the x coordinate of the mouse cursor within the game window. The left edge of the game window is the origin.
         */
        virtual int GetMouseX() = 0;

        /**
         * Poll the vertical coordinate of the mouse cursor.
         * @return the y coordinate of the mouse cursor within the game window. The top edge of the game window is the origin.
         */
        virtual int GetMouseY() = 0;

        virtual ~IInputManager() {}
    };

    std::shared_ptr<IInputManager> CreateIInputManager();
}

#endif
