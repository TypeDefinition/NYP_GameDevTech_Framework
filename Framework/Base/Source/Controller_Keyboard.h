#ifndef CONTROLLER_KEYBOARD_H
#define CONTROLLER_KEYBOARD_H

#include "SingletonTemplate.h"
#include <bitset>
#include <string>
#include <queue>
#include <GLFW\glfw3.h>

using std::bitset;

namespace controller {

	enum class KEY_STATE {
		PRESS = GLFW_PRESS,
		RELEASE = GLFW_RELEASE
	};

	enum class KEYS {
		UNKNOWN = GLFW_KEY_UNKNOWN,
		SPACE = GLFW_KEY_SPACE,
		APOSTROPHE = GLFW_KEY_APOSTROPHE,
		COMMA = GLFW_KEY_COMMA,
		MINUS = GLFW_KEY_MINUS,
		PERIOD = GLFW_KEY_PERIOD,
		SLASH = GLFW_KEY_SLASH,
		SEMICOLON = GLFW_KEY_SEMICOLON,
		EQUAL = GLFW_KEY_EQUAL,

		ONE = GLFW_KEY_0,
		TWO = GLFW_KEY_1,
		THREE = GLFW_KEY_2,
		FOUR = GLFW_KEY_3,
		FIVE = GLFW_KEY_4,
		SIX = GLFW_KEY_5,
		SEVEN = GLFW_KEY_6,
		EIGHT = GLFW_KEY_7,
		NINE = GLFW_KEY_8,
		TEN = GLFW_KEY_9,

		A = GLFW_KEY_A,
		B = GLFW_KEY_B,
		C = GLFW_KEY_C,
		D = GLFW_KEY_D,
		E = GLFW_KEY_E,
		F = GLFW_KEY_F,
		G = GLFW_KEY_G,
		H = GLFW_KEY_H,
		I = GLFW_KEY_I,
		J = GLFW_KEY_J,
		K = GLFW_KEY_K,
		L = GLFW_KEY_L,
		M = GLFW_KEY_M,
		N = GLFW_KEY_N,
		O = GLFW_KEY_O,
		P = GLFW_KEY_P,
		Q = GLFW_KEY_Q,
		R = GLFW_KEY_R,
		S = GLFW_KEY_S,
		T = GLFW_KEY_T,
		U = GLFW_KEY_U,
		V = GLFW_KEY_V,
		W = GLFW_KEY_W,
		X = GLFW_KEY_X,
		Y = GLFW_KEY_Y,
		Z = GLFW_KEY_Z,

		LEFT_BRACKET = GLFW_KEY_LEFT_BRACKET,
		BACKSLASH = GLFW_KEY_BACKSLASH,
		RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET,
		ACCENT = GLFW_KEY_GRAVE_ACCENT,
		WORLD_1 = GLFW_KEY_WORLD_1,
		WORLD_2 = GLFW_KEY_WORLD_2,
		ESCAPE = GLFW_KEY_ESCAPE,
		ENTER = GLFW_KEY_ENTER,
		TAB = GLFW_KEY_TAB,
		BACKSPACE = GLFW_KEY_BACKSPACE,
		INSERT = GLFW_KEY_INSERT,
		DEL = GLFW_KEY_DELETE,
		RIGHT = GLFW_KEY_RIGHT,
		LEFT = GLFW_KEY_LEFT,
		DOWN = GLFW_KEY_DOWN,
		UP = GLFW_KEY_UP,
		PAGE_UP = GLFW_KEY_PAGE_UP,
		PAGE_DOWN = GLFW_KEY_PAGE_DOWN,
		HOME = GLFW_KEY_HOME,
		END = GLFW_KEY_END,
		CAPS_LOCK = GLFW_KEY_CAPS_LOCK,
		SCROLL_LOCK = GLFW_KEY_SCROLL_LOCK,
		NUM_LOCK = GLFW_KEY_NUM_LOCK,
		PRINT_SCREEN = GLFW_KEY_PRINT_SCREEN,
		PAUSE = GLFW_KEY_PAUSE,

		F1 = GLFW_KEY_F1,
		F2 = GLFW_KEY_F2,
		F3 = GLFW_KEY_F3,
		F4 = GLFW_KEY_F4,
		F5 = GLFW_KEY_F5,
		F6 = GLFW_KEY_F6,
		F7 = GLFW_KEY_F7,
		F8 = GLFW_KEY_F8,
		F9 = GLFW_KEY_F9,
		F10 = GLFW_KEY_F10,
		F11 = GLFW_KEY_F11,
		F12 = GLFW_KEY_F12,

		F13 = GLFW_KEY_F13,
		F14 = GLFW_KEY_F14,
		F15 = GLFW_KEY_F15,
		F16 = GLFW_KEY_F16,
		F17 = GLFW_KEY_F17,
		F18 = GLFW_KEY_F18,
		F19 = GLFW_KEY_F19,
		F20 = GLFW_KEY_F20,
		F21 = GLFW_KEY_F21,
		F22 = GLFW_KEY_F22,
		F23 = GLFW_KEY_F23,
		F24 = GLFW_KEY_F24,
		F25 = GLFW_KEY_F25,

		KEYPAD_0 = GLFW_KEY_KP_0,
		KEYPAD_1 = GLFW_KEY_KP_1,
		KEYPAD_2 = GLFW_KEY_KP_2,
		KEYPAD_3 = GLFW_KEY_KP_3,
		KEYPAD_4 = GLFW_KEY_KP_4,
		KEYPAD_5 = GLFW_KEY_KP_5,
		KEYPAD_6 = GLFW_KEY_KP_6,
		KEYPAD_7 = GLFW_KEY_KP_7,
		KEYPAD_8 = GLFW_KEY_KP_8,
		KEYPAD_9 = GLFW_KEY_KP_9,
		KEYPAD_DECIMAL = GLFW_KEY_KP_DECIMAL,
		KEYPAD_DIVIDE = GLFW_KEY_KP_DIVIDE,
		KEYPAD_MULTIPLY = GLFW_KEY_KP_MULTIPLY,
		KEYPAD_SUBSTRACT = GLFW_KEY_KP_SUBTRACT,
		KEYPAD_ADD = GLFW_KEY_KP_ADD,
		KEYPAD_ENTER = GLFW_KEY_KP_ENTER,
		KEYPAD_EQUAL = GLFW_KEY_KP_EQUAL,

		LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT,
		LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL,
		LEFT_ALT = GLFW_KEY_LEFT_ALT,
		LEFT_WINDOWS = GLFW_KEY_LEFT_SUPER,
		RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT,
		RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL,
		RIGHT_ALT = GLFW_KEY_RIGHT_ALT,
		RIGHT_WINDOWS = GLFW_KEY_RIGHT_SUPER,

		MENU = GLFW_KEY_MENU
	};

	enum class MODIFIERS {
		SUPER,
		SHIFT,
		CTRL,
		ALT,
	};

	using Modifiers = bitset<4>;

	class Key {

	public:
		Key(KEYS key, KEY_STATE state, int scancode, Modifiers modifiers);

		KEYS GetKey() const;

		KEY_STATE GetState() const;

		template<MODIFIERS>
		bool GetModifier() const{
			static_assert(false, "Unsupported modifier!");
		}
		template<>
		bool GetModifier<MODIFIERS::SHIFT>() const;
		template<>
		bool GetModifier<MODIFIERS::CTRL>() const;
		template<>
		bool GetModifier<MODIFIERS::ALT>() const;
		template<>
		bool GetModifier<MODIFIERS::SUPER>() const;

		int GetScancode() const;

	private:
		KEYS key;
		KEY_STATE state;
		Modifiers modifiers;
		int scancode;

	};

	class Keyboard : public Singleton<Keyboard> {

	public:
		//Function(s)
		/*
		Returns a key from a buffer of keys typed at that frame. Will throw an exception once buffer is completely empty.
		To use, type out:
		try {
			while(true) {
				const Key the_key = GetKey();
				//Do something
			}
		} catch(std::exception d) {
			//no more keys left. Do nothing.
		}
		*/
		Key GetKey();
		int GetUnicode();
		std::string GetClipboard();
		void SetClipboard(std::string string);

		void SetWindow(GLFWwindow*const window);
		void ClearInput();

	private:
		friend class Singleton<Keyboard>;

		//Constructor(s) & Destructor
		Keyboard();
		virtual ~Keyboard() {}

		std::queue<Key> key_queue;
		std::queue<int> unicode_queue;
		GLFWwindow* window;

	};

}
#endif