//
//  Keyboard.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Keyboard.h"
#include "Display.h"
#include "../Strings.h"
#include <GLFW/glfw3.h>


using namespace age;
using namespace age::gui;






Keyboard::Keyboard(Display *display) : display(display) {
	
}


bool Keyboard::IsKeyPressed(Key key) {
	return glfwGetKey((GLFWwindow*)display->GetWindowHandle(), (int)key);
}
bool Keyboard::IsKeyCharPressed(char key) {
	return glfwGetKey((GLFWwindow*)display->GetWindowHandle(), CharToKey(key));
}
bool Keyboard::IsKeyNamePressed(const std::string &name_) {
	if ( name_.length() == 1 ) return IsKeyCharPressed(name_[0]);
	else {
		std::string name = StringToLowercase(name_);
		if ( StringMatches(name, "space") ) return IsKeyPressed(AGE_KEY_SPACE);
		else if ( StringMatches(name, "enter") ) return IsKeyPressed(AGE_KEY_ENTER);
		else return false;
	}
}


Key gui::CharToKey(char c) {
	if      ( c >= 'A' && c <= 'Z' ) return Key(AGE_KEY_A + (c - 'A'));
	else if ( c >= 'a' && c <= 'z' ) return Key(AGE_KEY_A + (c - 'a'));
	else if ( c >= '0' && c <= '0' ) return Key(AGE_KEY_0 + (c - '0'));
	else switch ( c ) {
		case ' ': return AGE_KEY_SPACE;
		case '\t': return AGE_KEY_TAB;
		case '\n': return AGE_KEY_ENTER;
		case '[' : return AGE_KEY_LEFT_BRACKET;
		case ']' : return AGE_KEY_RIGHT_BRACKET;
		case '\\' : return AGE_KEY_BACKSLASH;
		case ';' : return AGE_KEY_SEMICOLON;
		case '\'' : return AGE_KEY_APOSTROPHE;
		case ',' : return AGE_KEY_COMMA;
		case '.' : return AGE_KEY_PERIOD;
		case '/' : return AGE_KEY_SLASH;
		case '`' : return AGE_KEY_GRAVE;
		default: return AGE_KEY_UNKNOWN;
	}
}
char gui::KeyToChar(Key k) {
	if      ( k >= AGE_KEY_A && k <= AGE_KEY_Z ) return (char)(k - AGE_KEY_A) + 'A';
	else if ( k >= AGE_KEY_0 && k <= AGE_KEY_0 ) return (char)(k - AGE_KEY_0) + '0';
	else switch ( k ) {
		case AGE_KEY_SPACE : return ' ';
		case AGE_KEY_TAB : return '\t';
		case AGE_KEY_ENTER : return '\n';
		case AGE_KEY_APOSTROPHE : return '\'';
		case AGE_KEY_BACKSLASH : return '\\';
		case AGE_KEY_COMMA : return ',';
		case AGE_KEY_GRAVE : return '`';
		case AGE_KEY_LEFT_BRACKET : return '[';
		case AGE_KEY_RIGHT_BRACKET : return ']';
		case AGE_KEY_SEMICOLON : return ';';
		case AGE_KEY_PERIOD : return '.';
		case AGE_KEY_SLASH : return '/';
		default: return '\0';
	}
}




