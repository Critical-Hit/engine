#include "Key.h"
#include <GLFW/glfw3.h>

Key::Key(int keyCode)
{
    this->KeyCode = keyCode;
    // Map the engine keyboard to a GLFW keycode
    switch (keyCode) {
    case KEYBOARD_A:
        this->GlfwKeyCode = GLFW_KEY_A;
        break;
    case KEYBOARD_B:
        this->GlfwKeyCode = GLFW_KEY_B;
        break;
    case KEYBOARD_C:
        this->GlfwKeyCode = GLFW_KEY_C;
        break;
    case KEYBOARD_D:
        this->GlfwKeyCode = GLFW_KEY_D;
        break;
    case KEYBOARD_E:
        this->GlfwKeyCode = GLFW_KEY_E;
        break;
    case KEYBOARD_F:
        this->GlfwKeyCode = GLFW_KEY_F;
        break;
    case KEYBOARD_G:
        this->GlfwKeyCode = GLFW_KEY_G;
        break;
    case KEYBOARD_H:
        this->GlfwKeyCode = GLFW_KEY_H;
        break;
    case KEYBOARD_I:
        this->GlfwKeyCode = GLFW_KEY_I;
        break;
    case KEYBOARD_J:
        this->GlfwKeyCode = GLFW_KEY_J;
        break;
    case KEYBOARD_K:
        this->GlfwKeyCode = GLFW_KEY_K;
        break;
    case KEYBOARD_L:
        this->GlfwKeyCode = GLFW_KEY_L;
        break;
    case KEYBOARD_M:
        this->GlfwKeyCode = GLFW_KEY_M;
        break;
    case KEYBOARD_N:
        this->GlfwKeyCode = GLFW_KEY_N;
        break;
    case KEYBOARD_O:
        this->GlfwKeyCode = GLFW_KEY_O;
        break;
    case KEYBOARD_P:
        this->GlfwKeyCode = GLFW_KEY_P;
        break;
    case KEYBOARD_Q:
        this->GlfwKeyCode = GLFW_KEY_Q;
        break;
    case KEYBOARD_R:
        this->GlfwKeyCode = GLFW_KEY_R;
        break;
    case KEYBOARD_S:
        this->GlfwKeyCode = GLFW_KEY_S;
        break;
    case KEYBOARD_T:
        this->GlfwKeyCode = GLFW_KEY_T;
        break;
    case KEYBOARD_U:
        this->GlfwKeyCode = GLFW_KEY_U;
        break;
    case KEYBOARD_V:
        this->GlfwKeyCode = GLFW_KEY_V;
        break;
    case KEYBOARD_W:
        this->GlfwKeyCode = GLFW_KEY_W;
        break;
    case KEYBOARD_X:
        this->GlfwKeyCode = GLFW_KEY_X;
        break;
    case KEYBOARD_Y:
        this->GlfwKeyCode = GLFW_KEY_Y;
        break;
    case KEYBOARD_Z:
        this->GlfwKeyCode = GLFW_KEY_Z;
        break;
    case KEYBOARD_1:
        this->GlfwKeyCode = GLFW_KEY_1;
        break;
    case KEYBOARD_2:
        this->GlfwKeyCode = GLFW_KEY_2;
        break;
    case KEYBOARD_3:
        this->GlfwKeyCode = GLFW_KEY_3;
        break;
    case KEYBOARD_4:
        this->GlfwKeyCode = GLFW_KEY_4;
        break;
    case KEYBOARD_5:
        this->GlfwKeyCode = GLFW_KEY_5;
        break;
    case KEYBOARD_6:
        this->GlfwKeyCode = GLFW_KEY_6;
        break;
    case KEYBOARD_7:
        this->GlfwKeyCode = GLFW_KEY_7;
        break;
    case KEYBOARD_8:
        this->GlfwKeyCode = GLFW_KEY_8;
        break;
    case KEYBOARD_9:
        this->GlfwKeyCode = GLFW_KEY_9;
        break;
    case KEYBOARD_0:
        this->GlfwKeyCode = GLFW_KEY_0;
        break;
    case KEYBOARD_ENTER:
        this->GlfwKeyCode = GLFW_KEY_ENTER;
        break;
    case KEYBOARD_ESCAPE:
        this->GlfwKeyCode = GLFW_KEY_ESCAPE;
        break;
    case KEYBOARD_BACKSPACE:
        this->GlfwKeyCode = GLFW_KEY_BACKSPACE;
        break;
    case KEYBOARD_TAB:
        this->GlfwKeyCode = GLFW_KEY_TAB;
        break;
    case KEYBOARD_SPACEBAR:
        this->GlfwKeyCode = GLFW_KEY_SPACE;
        break;
    case KEYBOARD_MINUS:
        this->GlfwKeyCode = GLFW_KEY_MINUS;
        break;
    case KEYBOARD_EQUALS:
        this->GlfwKeyCode = GLFW_KEY_EQUAL;
        break;
    case KEYBOARD_LEFT_BRACKET:
        this->GlfwKeyCode = GLFW_KEY_LEFT_BRACKET;
        break;
    case KEYBOARD_RIGHT_BRACKET:
        this->GlfwKeyCode = GLFW_KEY_RIGHT_BRACKET;
        break;
    case KEYBOARD_BACKSLASH:
        this->GlfwKeyCode = GLFW_KEY_BACKSLASH;
        break;
    case KEYBOARD_SEMICOLON:
        this->GlfwKeyCode = GLFW_KEY_SEMICOLON;
        break;
    case KEYBOARD_QUOTE:
        this->GlfwKeyCode = GLFW_KEY_APOSTROPHE;
        break;
    case KEYBOARD_GRAVE_ACCENT:
        this->GlfwKeyCode = GLFW_KEY_GRAVE_ACCENT;
        break;
    case KEYBOARD_COMMA:
        this->GlfwKeyCode = GLFW_KEY_COMMA;
        break;
    case KEYBOARD_PERIOD:
        this->GlfwKeyCode = GLFW_KEY_PERIOD;
        break;
    case KEYBOARD_FORWARD_SLASH:
        this->GlfwKeyCode = GLFW_KEY_SLASH
        break;
    case KEYBOARD_CAPS_LOCK:
        this->GlfwKeyCode = GLFW_KEY_CAPS_LOCK;
        break;
    case KEYBOARD_F1:
        this->GlfwKeyCode = GLFW_KEY_F1;
        break;
    case KEYBOARD_F2:
        this->GlfwKeyCode = GLFW_KEY_F2;
        break;
    case KEYBOARD_F3:
        this->GlfwKeyCode = GLFW_KEY_F3;
        break;
    case KEYBOARD_F4:
        this->GlfwKeyCode = GLFW_KEY_F4;
        break;
    case KEYBOARD_F5:
        this->GlfwKeyCode = GLFW_KEY_F5;
        break;
    case KEYBOARD_F6:
        this->GlfwKeyCode = GLFW_KEY_F6;
        break;
    case KEYBOARD_F7:
        this->GlfwKeyCode = GLFW_KEY_F7;
        break;
    case KEYBOARD_F8:
        this->GlfwKeyCode = GLFW_KEY_F8;
        break;
    case KEYBOARD_F9:
        this->GlfwKeyCode = GLFW_KEY_F9;
        break;
    case KEYBOARD_F10:
        this->GlfwKeyCode = GLFW_KEY_F10;
        break;
    case KEYBOARD_F11:
        this->GlfwKeyCode = GLFW_KEY_F11;
        break;
    case KEYBOARD_F12:
        this->GlfwKeyCode = GLFW_KEY_F12;
        break;
    case KEYBOARD_PRINT_SCREEN:
        this->GlfwKeyCode = GLFW_KEY_PRINT_SCREEN;
        break;
    case KEYBOARD_SCROLL_LOCK:
        this->GlfwKeyCode = GLFW_KEY_SCROLL_LOCK;
        break;
    case KEYBOARD_PAUSE:
        this->GlfwKeyCode = GLFW_KEY_PAUSE;
        break;
    case KEYBOARD_INSERT:
        this->GlfwKeyCode = GLFW_KEY_INSERT;
        break;
    case KEYBOARD_HOME:
        this->GlfwKeyCode = GLFW_KEY_HOME;
        break;
    case KEYBOARD_PAGE_UP:
        this->GlfwKeyCode = GLFW_KEY_PAGE_UP;
        break;
    case KEYBOARD_DELETE:
        this->GlfwKeyCode = GLFW_KEY_DELETE;
        break;
    case KEYBOARD_END:
        this->GlfwKeyCode = GLFW_KEY_END;
        break;
    case KEYBOARD_PAGE_DOWN:
        this->GlfwKeyCode = GLFW_KEY_PAGE_DOWN;
        break;
    case KEYBOARD_RIGHT_ARROW:
        this->GlfwKeyCode = GLFW_KEY_RIGHT;
        break;
    case KEYBOARD_LEFT_ARROW:
        this->GlfwKeyCode = GLFW_KEY_LEFT;
        break;
    case KEYBOARD_DOWN_ARROW:
        this->GlfwKeyCode = GLFW_KEY_DOWN;
        break;
    case KEYBOARD_UP_ARROW:
        this->GlfwKeyCode = GLFW_KEY_UP;
        break;
    case KEYBOARD_NUM_LOCK:
        this->GlfwKeyCode = GLFW_KEY_NUM_LOCK;
        break;
    case KEYBOARD_NUM_FORWARD_SLASH:
        this->GlfwKeyCode = GLFW_KEY_KP_DIVIDE;
        break;
    case KEYBOARD_NUM_ASTERISK:
        this->GlfwKeyCode = GLFW_KEY_KP_MULTIPLY;
        break;
    case KEYBOARD_NUM_MINUS:
        this->GlfwKeyCode = GLFW_KEY_KP_SUBTRACT;
        break;
    case KEYBOARD_NUM_PLUS:
        this->GlfwKeyCode = GLFW_KEY_KP_ADD;
        break;
    case KEYBOARD_NUM_ENTER:
        this->GlfwKeyCode = GLFW_KEY_KP_ENTER;
        break;
    case KEYBOARD_NUM_1:
        this->GlfwKeyCode = GLFW_KEY_KP_1;
        break;
    case KEYBOARD_NUM_2:
        this->GlfwKeyCode = GLFW_KEY_KP_2;
        break;
    case KEYBOARD_NUM_3:
        this->GlfwKeyCode = GLFW_KEY_KP_3;
        break;
    case KEYBOARD_NUM_4:
        this->GlfwKeyCode = GLFW_KEY_KP_4;
        break;
    case KEYBOARD_NUM_5:
        this->GlfwKeyCode = GLFW_KEY_KP_5;
        break;
    case KEYBOARD_NUM_6:
        this->GlfwKeyCode = GLFW_KEY_KP_6;
        break;
    case KEYBOARD_NUM_7:
        this->GlfwKeyCode = GLFW_KEY_KP_7;
        break;
    case KEYBOARD_NUM_8:
        this->GlfwKeyCode = GLFW_KEY_KP_8;
        break;
    case KEYBOARD_NUM_9:
        this->GlfwKeyCode = GLFW_KEY_KP_9;
        break;
    case KEYBOARD_NUM_0:
        this->GlfwKeyCode = GLFW_KEY_KP_0;
        break;
    case KEYBOARD_NUM_PERIOD:
        this->GlfwKeyCode = GLFW_KEY_KP_DECIMAL;
        break;
    case KEYBOARD_NUM_EQUALS:
        this->GlfwKeyCode = GLFW_KEY_KP_EQUAL;
        break;
    case KEYBOARD_LEFT_CONTROL:
        this->GlfwKeyCode = GLFW_KEY_LEFT_CONTROL;
        break;
    case KEYBOARD_LEFT_SHIFT:
        this->GlfwKeyCode = GLFW_KEY_LEFT_SHIFT;
        break;
    case KEYBOARD_LEFT_ALT:
        this->GlfwKeyCode = GLFW_KEY_LEFT_ALT;
        break;
    case KEYBOARD_LEFT_SUPER:
        this->GlfwKeyCode = GLFW_KEY_LEFT_SUPER;
        break;
    case KEYBOARD_RIGHT_CONTROL:
        this->GlfwKeyCode = GLFW_KEY_RIGHT_CONTROL;
        break;
    case KEYBOARD_RIGHT_SHIFT:
        this->GlfwKeyCode = GLFW_KEY_RIGHT_SHIFT;
        break;
    case KEYBOARD_RIGHT_ALT:
        this->GlfwKeyCode = GLFW_KEY_RIGHT_ALT;
        break;
    case KEYBOARD_RIGHT_SUPER:
        this->GlfwKeyCode = GLFW_KEY_RIGHT_SUPER;
        break;
    }
}
