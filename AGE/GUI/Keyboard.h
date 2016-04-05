//
//  Keyboard.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Keyboard__
#define __AGE__Keyboard__

#include <string>

namespace age {
	namespace gui {
		enum Key {
			AGE_KEY_UNKNOWN = -1,
			
			AGE_KEY_SPACE = 32,
			AGE_KEY_APOSTROPHE = 39,
			AGE_KEY_COMMA = 44,
			AGE_KEY_MINUS = 45,
			AGE_KEY_PERIOD = 46,
			AGE_KEY_SLASH = 47,
			AGE_KEY_SEMICOLON = 59,
			AGE_KEY_EQUALS = 61,
			AGE_KEY_LEFT_BRACKET = 91,
			AGE_KEY_BACKSLASH = 92,
			AGE_KEY_RIGHT_BRACKET = 93,
			AGE_KEY_GRAVE = 94,
			
			AGE_KEY_0 = 48,
			AGE_KEY_1,
			AGE_KEY_2,
			AGE_KEY_3,
			AGE_KEY_4,
			AGE_KEY_5,
			AGE_KEY_6,
			AGE_KEY_7,
			AGE_KEY_8,
			AGE_KEY_9,
			
			AGE_KEY_A = 65,
			AGE_KEY_B,
			AGE_KEY_C,
			AGE_KEY_D,
			AGE_KEY_E,
			AGE_KEY_F,
			AGE_KEY_G,
			AGE_KEY_H,
			AGE_KEY_I,
			AGE_KEY_J,
			AGE_KEY_K,
			AGE_KEY_L,
			AGE_KEY_M,
			AGE_KEY_N,
			AGE_KEY_O,
			AGE_KEY_P,
			AGE_KEY_Q,
			AGE_KEY_R,
			AGE_KEY_S,
			AGE_KEY_T,
			AGE_KEY_U,
			AGE_KEY_V,
			AGE_KEY_W,
			AGE_KEY_X,
			AGE_KEY_Y,
			AGE_KEY_Z,
			
			AGE_KEY_F1 = 290,
			AGE_KEY_F2,
			AGE_KEY_F3,
			AGE_KEY_F4,
			AGE_KEY_F5,
			AGE_KEY_F6,
			AGE_KEY_F7,
			AGE_KEY_F8,
			AGE_KEY_F9,
			AGE_KEY_F10,
			AGE_KEY_F11,
			AGE_KEY_F12,
			
			
			
			AGE_KEY_ESCAPE = 256,
			AGE_KEY_ENTER = 257,
			AGE_KEY_TAB = 258,
			AGE_KEY_BACKSPACE = 259,
			AGE_KEY_INSERT = 260,
			AGE_KEY_DELETE = 261,
			AGE_KEY_RIGHT = 262,
			AGE_KEY_LEFT,
			AGE_KEY_DOWN,
			AGE_KEY_UP,
			
			AGE_KEY_CAPS_LOCK = 280,
			AGE_KEY_LEFT_SHIFT = 340,
			AGE_KEY_LEFT_CONTROL,
			AGE_KEY_LEFT_ALT,
			AGE_KEY_LEFT_META,
			AGE_KEY_RIGHT_SHIFT,
			AGE_KEY_RIGHT_CONTROL,
			AGE_KEY_RIGHT_ALT,
			AGE_KEY_RIGHT_META,
		};
		
		class Display;
		
		/** Keyboard class */
		class Keyboard {
			Display *display;
			
		public:
			Keyboard(Display *display);
			
			
			
			bool IsKeyPressed(Key key);
			bool IsKeyCharPressed(char key);
			bool IsKeyNamePressed(const std::string &name);
		};
		
		/** Converts a character to a key */
		Key CharToKey(char c);
		/** Converts a key to a character */
		char KeyToChar(Key k);
	}
}

#endif /* defined(__AGE__Keyboard__) */
