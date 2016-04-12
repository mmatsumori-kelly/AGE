//
//  Display.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/22/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Display.h"
#include "GLFW.h"
#include "../Debug.h"
#include "../AGE.h"

using namespace age;
using namespace age::gui;



Display::Display(void *window) : window(window), keyboard(this), mouse(this) {
	
}
Display::~Display() {
	glfwDestroyWindow((GLFWwindow*)window);
}

Display* Display::New() {
	GLFW::Init();
	
	// Window creation hints
	glfwWindowHint(GLFW_DEPTH_BITS, 16);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_SAMPLES, 2);
	
	// Create the window
	GLFWwindow *window = glfwCreateWindow(800, 500, "Abstracted Game Engine", nullptr, nullptr);
	
	
	// Error
	if ( window == nullptr ) {
		LogError("Could not create GLFW window");
		return nullptr;
	}
	// Success
	else {
		LogMessage("Successfully created GLFW window");
		
		
		glClearColor(1, 0, 1, 1);
		
		
		// Depth testing
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		glClearDepth(1.0f);
		
		// Face culling
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glFrontFace(GL_CCW);
		
		
		
		
		
		// Return the window
		return new Display(window);
	}
}


void Display::CaptureMouse(bool captured) {
	glfwSetInputMode((GLFWwindow*)window, GLFW_CURSOR, captured ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}

void Display::Maximize() {
	const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	SetLocation(IVec2(0, 0));
	SetSize(IVec2(mode->width - 1, mode->height - 1));
}
void Display::MakeCurrent() {
	glfwMakeContextCurrent((GLFWwindow*)window);
}


void Display::SetTitle(const std::string &name) {
	glfwSetWindowTitle((GLFWwindow*)window, name.c_str());
}
void Display::SetLocation(const IVec2 &location) {
	glfwSetWindowPos((GLFWwindow*)window, location.x, location.y);
}
void Display::SetSize(const IVec2 &size) {
	glfwSetWindowSize((GLFWwindow*)window, size.x, size.y);
}
IVec2 Display::GetSize() {
	int w, h;
	glfwGetWindowSize((GLFWwindow*)window, &w, &h);
	return IVec2(w, h);
}
IVec2 Display::GetLocation() {
	int x, y;
	glfwGetWindowPos((GLFWwindow*)window, &x, &y);
	return IVec2(x, y);
}



void Display::BeginRender() {
	MakeCurrent();
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	

}
void Display::FinishRender() {
	glfwSwapBuffers((GLFWwindow*)window);
}
void Display::PollEvents(age::AGEDevice *device) {
	glfwPollEvents();
	if ( glfwWindowShouldClose((GLFWwindow*)window) ) {
		device->Stop();
	}
	
	mouse.Update();
}
















