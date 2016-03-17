//
//  Mouse.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Mouse.h"
#include "Display.h"
#include <GLFW/glfw3.h>

using namespace age::gui;




bool Mouse::IsButtonPressed(age::gui::MouseButton button) {
	return glfwGetMouseButton((GLFWwindow*)display->GetWindowHandle(), button);
}

void Mouse::Update() {
	old_x = x;
	old_y = y;
	
	glfwGetCursorPos((GLFWwindow*)display->GetWindowHandle(), &x, &y);
	
	if ( first_update ) {
		old_x = x;
		old_y = y;
		first_update = false;
	}
}




