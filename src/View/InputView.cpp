#include "InputView.h"
#include "GLFW/glfw3.h"
#include "KeyPressEvent.h"
#include "KeyReleaseEvent.h"
#include <set>
#include "assert.h"
InputView* InputView::instance;

InputView::InputView(GLFWwindow* window)
{
    this->window = window;
    this->inputManager = nullptr;
    InputView::instance = this;
};

void InputView::Initialize()
{
    glfwSetInputMode(window, GLFW_CURSOR_NORMAL, GL_FALSE);
	glfwSetKeyCallback(window, InputView::keyCallbackDispatcher);
}

void InputView::Update(InputManager* inputManager)
{
	this->inputManager = inputManager;
}

void InputView::keyCallback(GLFWwindow* window, int key, int, int action, int)
{
	assert(window);
    if (inputManager != nullptr)
    {
   	    KeyCode keyCode = InputView::keyCode(key);
	    if ((inputManager->IsRegisteredKeyPress(&keyCode)) && (action == GLFW_PRESS))
	    {
		    KeyPressEvent event(&keyCode);
		    inputManager->OnKeyPressEvent(&event);
	    } 
	    else if ((inputManager->IsRegisteredKeyRelease(&keyCode)) && (action == GLFW_RELEASE))
	    {
	    	KeyReleaseEvent event(&keyCode);
	    	inputManager->OnKeyReleaseEvent(&event);
	    }
    }
}

void InputView::keyCallbackDispatcher(GLFWwindow* window, int key, int scanCode, int action, int mods)
{
    if (InputView::instance)
    {
        InputView::instance->keyCallback(window, key, scanCode, action, mods);
    }
}

InputState InputView::GetKeyState(KeyCode keyCode)
{
    int glfwKeyCode = InputView::glfwKeyCode(keyCode);
    int state = glfwGetKey(this->window, glfwKeyCode);
    return InputView::keyState(state);
}

InputState InputView::keyState(int glfwKeyState)
{
    switch (glfwKeyState) {
        case GLFW_RELEASE:
            return InputState::RELEASED;
        case GLFW_PRESS:
            return InputState::PRESSED;
        case GLFW_REPEAT:
            return InputState::PRESSED;
        default:
            return InputState::INVALID;
    }
}

KeyCode InputView::keyCode(int glfwKeyCode)
{
	switch (glfwKeyCode) {
		case GLFW_KEY_A:
		    return KeyCode::KEYBOARD_A;
		case GLFW_KEY_B:
		    return KeyCode::KEYBOARD_B;
		case GLFW_KEY_C:
		    return KeyCode::KEYBOARD_C;
		case GLFW_KEY_D:
		    return KeyCode::KEYBOARD_D;
		case GLFW_KEY_E:
		    return KeyCode::KEYBOARD_E;
		case GLFW_KEY_F:
		    return KeyCode::KEYBOARD_F;
		case GLFW_KEY_G:
		    return KeyCode::KEYBOARD_G;
		case GLFW_KEY_H:
		    return KeyCode::KEYBOARD_H;
		case GLFW_KEY_I:
	    	return KeyCode::KEYBOARD_I;
		case GLFW_KEY_J:
	    	return KeyCode::KEYBOARD_J;
		case GLFW_KEY_K:
	    	return KeyCode::KEYBOARD_K;
		case GLFW_KEY_L:
	    	return KeyCode::KEYBOARD_L;
		case GLFW_KEY_M:
	    	return KeyCode::KEYBOARD_M;
		case GLFW_KEY_N:
	    	return KeyCode::KEYBOARD_N;
		case GLFW_KEY_O:
	    	return KeyCode::KEYBOARD_O;
		case GLFW_KEY_P:
	    	return KeyCode::KEYBOARD_P;
		case GLFW_KEY_Q:
	    	return KeyCode::KEYBOARD_Q;
		case GLFW_KEY_R:
	    	return KeyCode::KEYBOARD_R;
		case GLFW_KEY_S:
	    	return KeyCode::KEYBOARD_S;
		case GLFW_KEY_T:
	    	return KeyCode::KEYBOARD_T;
		case GLFW_KEY_U:
	    	return KeyCode::KEYBOARD_U;
		case GLFW_KEY_V:
	    	return KeyCode::KEYBOARD_V;
		case GLFW_KEY_W:
	    	return KeyCode::KEYBOARD_W;
		case GLFW_KEY_X:
	    	return KeyCode::KEYBOARD_X;
		case GLFW_KEY_Y:
	    	return KeyCode::KEYBOARD_Y;
		case GLFW_KEY_Z:
	    	return KeyCode::KEYBOARD_Z;
		case GLFW_KEY_1:
	    	return KeyCode::KEYBOARD_1;
		case GLFW_KEY_2:
	    	return KeyCode::KEYBOARD_2;
		case GLFW_KEY_3:
	    	return KeyCode::KEYBOARD_3;
		case GLFW_KEY_4:
	    	return KeyCode::KEYBOARD_4;
		case GLFW_KEY_5:
	    	return KeyCode::KEYBOARD_5;
		case GLFW_KEY_6:
	    	return KeyCode::KEYBOARD_6;
		case GLFW_KEY_7:
	    	return KeyCode::KEYBOARD_7;
		case GLFW_KEY_8:
	    	return KeyCode::KEYBOARD_8;
		case GLFW_KEY_9:
	    	return KeyCode::KEYBOARD_9;
		case GLFW_KEY_0:
	    	return KeyCode::KEYBOARD_0;
		case GLFW_KEY_ENTER:
	    	return KeyCode::KEYBOARD_ENTER;
		case GLFW_KEY_ESCAPE:
	    	return KeyCode::KEYBOARD_ESCAPE;
		case GLFW_KEY_BACKSPACE:
	    	return KeyCode::KEYBOARD_BACKSPACE;
		case GLFW_KEY_TAB:
	    	return KeyCode::KEYBOARD_TAB;
		case GLFW_KEY_SPACE:
		    return KeyCode::KEYBOARD_SPACEBAR;
		case GLFW_KEY_MINUS:
    		return KeyCode::KEYBOARD_MINUS;
		case GLFW_KEY_EQUAL:
	    	return KeyCode::KEYBOARD_EQUALS;
		case GLFW_KEY_LEFT_BRACKET:
	    	return KeyCode::KEYBOARD_LEFT_BRACKET;
		case GLFW_KEY_RIGHT_BRACKET:
	    	return KeyCode::KEYBOARD_RIGHT_BRACKET;
		case GLFW_KEY_BACKSLASH:
    		return KeyCode::KEYBOARD_BACKSLASH;
		case GLFW_KEY_SEMICOLON:
    		return KeyCode::KEYBOARD_SEMICOLON;
		case GLFW_KEY_APOSTROPHE:
    		return KeyCode::KEYBOARD_QUOTE;
		case GLFW_KEY_GRAVE_ACCENT:
    		return KeyCode::KEYBOARD_GRAVE_ACCENT;
		case GLFW_KEY_COMMA:
    		return KeyCode::KEYBOARD_COMMA;
		case GLFW_KEY_PERIOD:
    		return KeyCode::KEYBOARD_PERIOD;
		case GLFW_KEY_SLASH:
    		return KeyCode::KEYBOARD_FORWARD_SLASH;
		case GLFW_KEY_CAPS_LOCK:
    		return KeyCode::KEYBOARD_CAPS_LOCK;
		case GLFW_KEY_F1:
    		return KeyCode::KEYBOARD_F1;
		case GLFW_KEY_F2:
	    	return KeyCode::KEYBOARD_F2;
		case GLFW_KEY_F3:
    		return KeyCode::KEYBOARD_F3;
		case GLFW_KEY_F4:
	    	return KeyCode::KEYBOARD_F4;
		case GLFW_KEY_F5:
	    	return KeyCode::KEYBOARD_F5;
		case GLFW_KEY_F6:
	    	return KeyCode::KEYBOARD_F6;
		case GLFW_KEY_F7:
	    	return KeyCode::KEYBOARD_F7;
		case GLFW_KEY_F8:
	    	return KeyCode::KEYBOARD_F8;
		case GLFW_KEY_F9:
	    	return KeyCode::KEYBOARD_F9;
		case GLFW_KEY_F10:
	    	return KeyCode::KEYBOARD_F10;
		case GLFW_KEY_F11:
    		return KeyCode::KEYBOARD_F11;
		case GLFW_KEY_F12:
    		return KeyCode::KEYBOARD_F12;
		case GLFW_KEY_PRINT_SCREEN:
    		return KeyCode::KEYBOARD_PRINT_SCREEN;
		case GLFW_KEY_SCROLL_LOCK:
    		return KeyCode::KEYBOARD_SCROLL_LOCK;
		case GLFW_KEY_PAUSE:
    		return KeyCode::KEYBOARD_PAUSE;
		case GLFW_KEY_INSERT:
    		return KeyCode::KEYBOARD_INSERT;
		case GLFW_KEY_HOME:
    		return KeyCode::KEYBOARD_HOME;
		case GLFW_KEY_PAGE_UP:
	    	return KeyCode::KEYBOARD_PAGE_UP;
		case GLFW_KEY_DELETE:
	    	return KeyCode::KEYBOARD_DELETE;
		case GLFW_KEY_END:
    		return KeyCode::KEYBOARD_END;
		case GLFW_KEY_PAGE_DOWN:
    		return KeyCode::KEYBOARD_PAGE_DOWN;
		case GLFW_KEY_RIGHT:
    		return KeyCode::KEYBOARD_RIGHT_ARROW;
		case GLFW_KEY_LEFT:
    		return KeyCode::KEYBOARD_LEFT_ARROW;
		case GLFW_KEY_DOWN:
    		return KeyCode::KEYBOARD_DOWN_ARROW;
		case GLFW_KEY_UP:
    		return KeyCode::KEYBOARD_UP_ARROW;
		case GLFW_KEY_NUM_LOCK:
    		return KeyCode::KEYBOARD_NUM_LOCK;
		case GLFW_KEY_KP_DIVIDE:
    		return KeyCode::KEYBOARD_NUM_FORWARD_SLASH;
		case GLFW_KEY_KP_MULTIPLY:
	    	return KeyCode::KEYBOARD_NUM_ASTERISK;
    	case GLFW_KEY_KP_SUBTRACT:
    		return KeyCode::KEYBOARD_NUM_MINUS;
		case GLFW_KEY_KP_ADD:
    		return KeyCode::KEYBOARD_NUM_PLUS;
		case GLFW_KEY_KP_ENTER:
    		return KeyCode::KEYBOARD_NUM_ENTER;
		case GLFW_KEY_KP_1:
    		return KeyCode::KEYBOARD_NUM_1;
		case GLFW_KEY_KP_2:
    		return KeyCode::KEYBOARD_NUM_2;
		case GLFW_KEY_KP_3:
    		return KeyCode::KEYBOARD_NUM_3;
		case GLFW_KEY_KP_4:
    		return KeyCode::KEYBOARD_NUM_4;
		case GLFW_KEY_KP_5:
    		return KeyCode::KEYBOARD_NUM_5;
		case GLFW_KEY_KP_6:
	    	return KeyCode::KEYBOARD_NUM_6;
    	case GLFW_KEY_KP_7:
	    	return KeyCode::KEYBOARD_NUM_7;
		case GLFW_KEY_KP_8:
	    	return KeyCode::KEYBOARD_NUM_8;
		case GLFW_KEY_KP_9:
	    	return KeyCode::KEYBOARD_NUM_9;
		case GLFW_KEY_KP_0:
	    	return KeyCode::KEYBOARD_NUM_0;
		case GLFW_KEY_KP_DECIMAL:
	    	return KeyCode::KEYBOARD_NUM_PERIOD;
		case GLFW_KEY_KP_EQUAL:
	    	return KeyCode::KEYBOARD_NUM_EQUALS;
		case GLFW_KEY_LEFT_CONTROL:
	    	return KeyCode::KEYBOARD_LEFT_CONTROL;
		case GLFW_KEY_LEFT_SHIFT:
	    	return KeyCode::KEYBOARD_LEFT_SHIFT;
		case GLFW_KEY_LEFT_ALT:
	    	return KeyCode::KEYBOARD_LEFT_ALT;
		case GLFW_KEY_LEFT_SUPER:
	    	return KeyCode::KEYBOARD_LEFT_SUPER;
		case GLFW_KEY_RIGHT_CONTROL:
	    	return KeyCode::KEYBOARD_RIGHT_CONTROL;
		case GLFW_KEY_RIGHT_SHIFT:
	    	return KeyCode::KEYBOARD_RIGHT_SHIFT;
		case GLFW_KEY_RIGHT_ALT:
	    	return KeyCode::KEYBOARD_RIGHT_ALT;
		case GLFW_KEY_RIGHT_SUPER:
	    	return KeyCode::KEYBOARD_RIGHT_SUPER;
		case GLFW_KEY_UNKNOWN:
	    	return KeyCode::KEYBOARD_UNKNOWN;
		default:
	    	return KeyCode::KEYBOARD_UNKNOWN;
	}
}

int InputView::glfwKeyCode(KeyCode keyCode) 
{
	switch (keyCode) {
		case KeyCode::KEYBOARD_A:
    		return GLFW_KEY_A;
		case KeyCode::KEYBOARD_B:
    		return GLFW_KEY_B;
		case KeyCode::KEYBOARD_C:
    		return GLFW_KEY_C;
		case KeyCode::KEYBOARD_D:
	    	return GLFW_KEY_D;
		case KeyCode::KEYBOARD_E:
	    	return GLFW_KEY_E;
		case KeyCode::KEYBOARD_F:
	    	return GLFW_KEY_F;
		case KeyCode::KEYBOARD_G:
	    	return GLFW_KEY_G;
		case KeyCode::KEYBOARD_H:
	    	return GLFW_KEY_H;
		case KeyCode::KEYBOARD_I:
    		return GLFW_KEY_I;
		case KeyCode::KEYBOARD_J:
    		return GLFW_KEY_J;
		case KeyCode::KEYBOARD_K:
    		return GLFW_KEY_K;
		case KeyCode::KEYBOARD_L:
    		return GLFW_KEY_L;
		case KeyCode::KEYBOARD_M:
    		return GLFW_KEY_M;
		case KeyCode::KEYBOARD_N:
	    	return GLFW_KEY_N;
		case KeyCode::KEYBOARD_O:
    		return GLFW_KEY_O;
		case KeyCode::KEYBOARD_P:
    		return GLFW_KEY_P;
		case KeyCode::KEYBOARD_Q:
    		return GLFW_KEY_Q;
		case KeyCode::KEYBOARD_R:
    		return GLFW_KEY_R;
		case KeyCode::KEYBOARD_S:
    		return GLFW_KEY_S;
		case KeyCode::KEYBOARD_T:
    		return GLFW_KEY_T;
		case KeyCode::KEYBOARD_U:
    		return GLFW_KEY_U;
		case KeyCode::KEYBOARD_V:
    		return GLFW_KEY_V;
		case KeyCode::KEYBOARD_W:
    		return GLFW_KEY_W;
		case KeyCode::KEYBOARD_X:
    		return GLFW_KEY_X;
   		case KeyCode::KEYBOARD_Y:
    		return GLFW_KEY_Y;
   		case KeyCode::KEYBOARD_Z:
		    return GLFW_KEY_Z;
		case KeyCode::KEYBOARD_1:
	    	return GLFW_KEY_1;
		case KeyCode::KEYBOARD_2:
	    	return GLFW_KEY_2;
		case KeyCode::KEYBOARD_3:
	    	return GLFW_KEY_3;
		case KeyCode::KEYBOARD_4:
	    	return GLFW_KEY_4;
		case KeyCode::KEYBOARD_5:
	    	return GLFW_KEY_5;
		case KeyCode::KEYBOARD_6:
	    	return GLFW_KEY_6;
		case KeyCode::KEYBOARD_7:
	    	return GLFW_KEY_7;
		case KeyCode::KEYBOARD_8:
	    	return GLFW_KEY_8;
		case KeyCode::KEYBOARD_9:
	    	return GLFW_KEY_9;
		case KeyCode::KEYBOARD_0:
	    	return GLFW_KEY_0;
		case KeyCode::KEYBOARD_ENTER:
	    	return GLFW_KEY_ENTER;
		case KeyCode::KEYBOARD_ESCAPE:
	    	return GLFW_KEY_ESCAPE;
		case KeyCode::KEYBOARD_BACKSPACE:
	    	return GLFW_KEY_BACKSPACE;
		case KeyCode::KEYBOARD_TAB:
	    	return GLFW_KEY_TAB;
		case KeyCode::KEYBOARD_SPACEBAR:
	    	return GLFW_KEY_SPACE;
		case KeyCode::KEYBOARD_MINUS:
	    	return GLFW_KEY_MINUS;
		case KeyCode::KEYBOARD_EQUALS:
	    	return GLFW_KEY_EQUAL;
		case KeyCode::KEYBOARD_LEFT_BRACKET:
	    	return GLFW_KEY_LEFT_BRACKET;
		case KeyCode::KEYBOARD_RIGHT_BRACKET:
	    	return GLFW_KEY_RIGHT_BRACKET;
		case KeyCode::KEYBOARD_BACKSLASH:
	    	return GLFW_KEY_BACKSLASH;
		case KeyCode::KEYBOARD_SEMICOLON:
	    	return GLFW_KEY_SEMICOLON;
		case KeyCode::KEYBOARD_QUOTE:
	    	return GLFW_KEY_APOSTROPHE;
		case KeyCode::KEYBOARD_GRAVE_ACCENT:
	    	return GLFW_KEY_GRAVE_ACCENT;
		case KeyCode::KEYBOARD_COMMA:
	    	return GLFW_KEY_COMMA;
		case KeyCode::KEYBOARD_PERIOD:
	    	return GLFW_KEY_PERIOD;
		case KeyCode::KEYBOARD_FORWARD_SLASH:
	    	return GLFW_KEY_SLASH;
		case KeyCode::KEYBOARD_CAPS_LOCK:
	    	return GLFW_KEY_CAPS_LOCK;
		case KeyCode::KEYBOARD_F1:
	    	return GLFW_KEY_F1;
		case KeyCode::KEYBOARD_F2:
	    	return GLFW_KEY_F2;
		case KeyCode::KEYBOARD_F3:
	    	return GLFW_KEY_F3;
		case KeyCode::KEYBOARD_F4:
	    	return GLFW_KEY_F4;
		case KeyCode::KEYBOARD_F5:
	    	return GLFW_KEY_F5;
		case KeyCode::KEYBOARD_F6:
	    	return GLFW_KEY_F6;
		case KeyCode::KEYBOARD_F7:
	    	return GLFW_KEY_F7;
		case KeyCode::KEYBOARD_F8:
	    	return GLFW_KEY_F8;
		case KeyCode::KEYBOARD_F9:
	    	return GLFW_KEY_F9;
		case KeyCode::KEYBOARD_F10:
	    	return GLFW_KEY_F10;
		case KeyCode::KEYBOARD_F11:
	    	return GLFW_KEY_F11;
		case KeyCode::KEYBOARD_F12:
	    	return GLFW_KEY_F12;
		case KeyCode::KEYBOARD_PRINT_SCREEN:
	    	return GLFW_KEY_PRINT_SCREEN;
		case KeyCode::KEYBOARD_SCROLL_LOCK:
	    	return GLFW_KEY_SCROLL_LOCK;
		case KeyCode::KEYBOARD_PAUSE:
	    	return GLFW_KEY_PAUSE;
		case KeyCode::KEYBOARD_INSERT:
	    	return GLFW_KEY_INSERT;
		case KeyCode::KEYBOARD_HOME:
	    	return GLFW_KEY_HOME;
		case KeyCode::KEYBOARD_PAGE_UP:
	    	return GLFW_KEY_PAGE_UP;
		case KeyCode::KEYBOARD_DELETE:
	    	return GLFW_KEY_DELETE;
		case KeyCode::KEYBOARD_END:
	    	return GLFW_KEY_END;
		case KeyCode::KEYBOARD_PAGE_DOWN:
	    	return GLFW_KEY_PAGE_DOWN;
		case KeyCode::KEYBOARD_RIGHT_ARROW:
	    	return GLFW_KEY_RIGHT;
		case KeyCode::KEYBOARD_LEFT_ARROW:
	    	return GLFW_KEY_LEFT;
		case KeyCode::KEYBOARD_DOWN_ARROW:
	    	return GLFW_KEY_DOWN;
		case KeyCode::KEYBOARD_UP_ARROW:
	    	return GLFW_KEY_UP;
		case KeyCode::KEYBOARD_NUM_LOCK:
	    	return GLFW_KEY_NUM_LOCK;
		case KeyCode::KEYBOARD_NUM_FORWARD_SLASH:
	    	return GLFW_KEY_KP_DIVIDE;
		case KeyCode::KEYBOARD_NUM_ASTERISK:
	    	return GLFW_KEY_KP_MULTIPLY;
		case KeyCode::KEYBOARD_NUM_MINUS:
	    	return GLFW_KEY_KP_SUBTRACT;
		case KeyCode::KEYBOARD_NUM_PLUS:
	    	return GLFW_KEY_KP_ADD;
		case KeyCode::KEYBOARD_NUM_ENTER:
	    	return GLFW_KEY_KP_ENTER;
		case KeyCode::KEYBOARD_NUM_1:
	    	return GLFW_KEY_KP_1;
		case KeyCode::KEYBOARD_NUM_2:
	    	return GLFW_KEY_KP_2;
		case KeyCode::KEYBOARD_NUM_3:
	    	return GLFW_KEY_KP_3;
		case KeyCode::KEYBOARD_NUM_4:
	    	return GLFW_KEY_KP_4;
		case KeyCode::KEYBOARD_NUM_5:
	    	return GLFW_KEY_KP_5;
		case KeyCode::KEYBOARD_NUM_6:
	    	return GLFW_KEY_KP_6;
		case KeyCode::KEYBOARD_NUM_7:
	    	return GLFW_KEY_KP_7;
		case KeyCode::KEYBOARD_NUM_8:
	       	return GLFW_KEY_KP_8;
		case KeyCode::KEYBOARD_NUM_9:
	     	return GLFW_KEY_KP_9;
		case KeyCode::KEYBOARD_NUM_0:
	     	return GLFW_KEY_KP_0;
		case KeyCode::KEYBOARD_NUM_PERIOD:
	     	return GLFW_KEY_KP_DECIMAL;
		case KeyCode::KEYBOARD_NUM_EQUALS:
	     	return GLFW_KEY_KP_EQUAL;
		case KeyCode::KEYBOARD_LEFT_CONTROL:
	     	return GLFW_KEY_LEFT_CONTROL;
		case KeyCode::KEYBOARD_LEFT_SHIFT:
	     	return GLFW_KEY_LEFT_SHIFT;
		case KeyCode::KEYBOARD_LEFT_ALT:
	     	return GLFW_KEY_LEFT_ALT;
		case KeyCode::KEYBOARD_LEFT_SUPER:
	     	return GLFW_KEY_LEFT_SUPER;
		case KeyCode::KEYBOARD_RIGHT_CONTROL:
	     	return GLFW_KEY_RIGHT_CONTROL;
		case KeyCode::KEYBOARD_RIGHT_SHIFT:
	     	return GLFW_KEY_RIGHT_SHIFT;
		case KeyCode::KEYBOARD_RIGHT_ALT:
	     	return GLFW_KEY_RIGHT_ALT;
		case KeyCode::KEYBOARD_RIGHT_SUPER:
	     	return GLFW_KEY_RIGHT_SUPER;
		case KeyCode::KEYBOARD_UNKNOWN:
	     	return GLFW_KEY_UNKNOWN;
		default:
		   return GLFW_KEY_UNKNOWN;
	}
}
