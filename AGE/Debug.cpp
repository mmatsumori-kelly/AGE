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
	const int buffer_size = 256;
	
	time_t ctime;
	struct tm *time_info;
	char buffer[buffer_size];
	
	time(&ctime);
	time_info = localtime(&ctime);
	
	strftime(buffer, buffer_size, format.c_str(), time_info);
	
	return buffer;
}





void age::PrintOpenGLErrors() {
	GLuint error = glGetError();
	if ( error == GL_NO_ERROR ) {
		LogError("OpenGL Error: no error");
	}
	else {
		do {
			LogError("OpenGL Error: %s", gluErrorString(error));
		} while ( (error = glGetError()) != GL_NO_ERROR );
	}
}





