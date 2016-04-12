//
//  Debug.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/25/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Debug.h"
#include <time.h>
#include <OpenGL/gl3.h>
#include <OpenGL/glu.h>



std::string age::GetFormattedTime(const std::string &format) {
	const int buffer_size = 512;
	
	
	// Find the local time
	time_t ctime;
	time(&ctime);
	
	// Create a buffer for the time string
	struct tm *time_info = localtime(&ctime);
	char buffer[buffer_size];
	
	// Format the string
	strftime(buffer, buffer_size, format.c_str(), time_info);
	
	return buffer;
}





void age::PrintOpenGLErrors() {
	GLuint error = glGetError();
	
	// No error, so notify that there were none
	if ( error == GL_NO_ERROR ) {
		LogError("OpenGL Error: no error");
	}
	// Loop through all the errors
	else {
		do {
			LogError("OpenGL Error: %s", gluErrorString(error));
		} while ( (error = glGetError()) != GL_NO_ERROR );
	}
}





