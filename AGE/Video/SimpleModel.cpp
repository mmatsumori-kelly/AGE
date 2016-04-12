//
//  SimpleModel.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "SimpleModel.h"
#include "../Strings.h"
#include "../Debug.h"
#include <OpenGL/gl3.h>

using namespace age;
using namespace age::video;




SimpleModel::SimpleModel(const std::vector<VertexInfo> &data, unsigned int vao, unsigned int vbo) : vertex_data(data), vao(vao), vbo(vbo) {
	
}
SimpleModel::~SimpleModel() {
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

SimpleModel* SimpleModel::Load(const age::File &file) {
	if ( !file.Exists() ) return nullptr;
	else {
		std::vector<FVec3> vertices, normals;
		std::vector<FVec2> uvs;
		
		// Read file by line
		std::vector<std::string> lines = file.ReadLines();
		for (std::string &line : lines) {
			line = StringTrim(line);
			if ( line.length() == 0 ) continue;
			else {
				
				// Split by spaces
				std::vector<std::string> split = StringSplitByChar(line, ' ');
				switch ( split[0][0] ) {
					case 'v':
						vertices.push_back(FVec3(atof(split[1].c_str()), atof(split[2].c_str()), atof(split[3].c_str())));
						break;
					case 'n':
						normals.push_back(FVec3(atof(split[1].c_str()), atof(split[2].c_str()), atof(split[3].c_str())));
						break;
					case 't':
						uvs.push_back(FVec2(atof(split[1].c_str()), atof(split[2].c_str())));
						break;
					default:
						continue;
				}
			}
		}
		
		
		// Check for errors
		if ( vertices.size() % 3 != 0 ) {
			LogError("Error loading model \"%s\": vertices not multiple of 3", (const char*)file);
			return nullptr;
		}
		else if ( normals.size() % 3 != 0 ) {
			LogError("Error loading model \"%s\": normals not multiple of 3", (const char*)file);
			return nullptr;
		}
		else if ( uvs.size() % 3 != 0 ) {
			LogError("Error loading model \"%s\": texture coords not multiple of 3", (const char*)file);
			return nullptr;
		}
		// No error
		else {
			
			// Interleave the data
			std::vector<VertexInfo> vertex_info;
			vertex_info.reserve(vertices.size() / 3);
			
			
			for (int i = 0; i < vertices.size(); ++i) {
				FVec3 &position = vertices[i];
				FVec3 normal(0, 0, 0);
				FVec2 uv(0, 0);
				
				if (  normals.size() != 0 ) normal = normals[i];
				if ( uvs.size() != 0 ) uv = uvs[i];
				
				vertex_info.push_back(VertexInfo(position, normal, uv));
			}
			
			
			// OpenGL VAO/VBO creation
			GLuint vao, vbo;
			glGenVertexArrays(1, &vao);
			glBindVertexArray(vao);
			
			glGenBuffers(1, &vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(VertexInfo) * vertex_info.size(), (GLfloat*)&vertex_info[0], GL_STATIC_DRAW);
			
			
			// Set up vertex attributes
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexInfo), (GLvoid*)0);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexInfo), (GLvoid*)3);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexInfo), (GLvoid*)5);
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(2);
			
			// Unbind
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
			
			
			
			// Finish up the model creation
			return new SimpleModel(vertex_info, vao, vbo);
		}
	}
}


void SimpleModel::Render() {
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, (int)vertex_data.size());
	glBindVertexArray(0);
}


