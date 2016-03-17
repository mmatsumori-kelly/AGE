//
//  GLFW.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/25/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "GLFW.h"
#include <GLFW/glfw3.h>
#include "../Debug.h"
#include <stdlib.h>

using namespace age::gui;



void GLFW_Error(int code, const char *msg) {
	age::LogError("Could not initialize GLFW: %s", msg);
}



GLFW GLFW::instance = GLFW();
GLFW::GLFW() : init(false) {
	
}
GLFW::~GLFW() {
	glfwTerminate();
}


void GLFW::Init() {
	if ( !IsInit() ) {
		glfwSetErrorCallback(GLFW_Error);
		
		// Initialize GLFW
		if ( !glfwInit() ) exit(1);
		else {
			// GLFW was successfully initialized
			int major, minor, revision;
			glfwGetVersion(&major, &minor, &revision);
			LogMessage("Successfully initialized GLFW %i.%i.%i", major, minor, revision);
			
			instance.init = true;
		}
	}
}



