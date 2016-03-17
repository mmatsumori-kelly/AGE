//
//  ManualModel.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/9/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "ManualModel.h"
#include <OpenGL/gl3.h>

using namespace age::video;




ManualModel::~ManualModel() {
	Destroy();
}



bool ManualModel::Create() {
	if ( !created ) {
		
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		
		// Upload the data to the GPU
		glBufferData(GL_ARRAY_BUFFER, sizeof(VertexInfo) * vertex_data.size(), (GLfloat*)&vertex_data[0], GL_STATIC_DRAW);
		
		// Bind attributes
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexInfo), (GLfloat*)0 + 0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexInfo), (GLfloat*)0 + 3);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_TRUE,  sizeof(VertexInfo), (GLfloat*)0 + 5);
		
		
		
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		
		
		return (created = true);
	}
	return false;
}
void ManualModel::Destroy() {
	vertex_data.clear();
	
	if ( created ) {
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		created = false;
	}
}



void ManualModel::Render() {
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, (int)vertex_data.size());
	glBindVertexArray(0);
}






