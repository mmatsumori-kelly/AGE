//
//  Shader.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/26/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Shader.h"
#include "../Debug.h"
#include <OpenGL/gl3.h>
#include <iostream>

using namespace age;
using namespace age::video;
using namespace std;


inline GLuint GetGLShaderType(ShaderType type) {
	switch ( type ) {
		case age::video::AGE_SHADER_VERTEX:
			return GL_VERTEX_SHADER;
		case age::video::AGE_SHADER_FRAGMENT:
			return GL_FRAGMENT_SHADER;
		default:
			return 0;
	}
}



ShaderSource::~ShaderSource() {
	glDeleteShader(GetID());
}
ShaderSource* ShaderSource::Load(const File &file, ShaderType shader_type) {
	if ( !file.Exists() ) return nullptr;
	return ShaderSource::New(file.ReadText(), shader_type);
}
ShaderSource* ShaderSource::New(const std::string &source, ShaderType shader_type) {
	GLuint shader = glCreateShader(GetGLShaderType(shader_type));
	
	// Load and compile the shader
	const char *vert_source_c = source.c_str();
	glShaderSource(shader, 1, &vert_source_c, NULL);
	glCompileShader(shader);
	
	// Check if the compilation was successful
	GLint success;
	GLchar info_log[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if ( !success ) {
		glGetShaderInfoLog(shader, 512, NULL, info_log);
		LogError("Shader Compilation error: %s", info_log);
		return nullptr;
	}
	else {
		return new ShaderSource(shader);
	}
}







ShaderProgram::ShaderProgram() : created(false) {
	program_id = glCreateProgram();
}
ShaderProgram::~ShaderProgram() {
	glDeleteProgram(program_id);
}

void ShaderProgram::AttachShader(ShaderSource *source) {
	if ( source != nullptr ) glAttachShader(program_id, source->GetID());
	else error << "Attempted to attach null shader" << endline;
}
bool ShaderProgram::LinkProgram() {
	if ( !IsLinked() ) {
		
		// Link the program
		glLinkProgram(program_id);
		
		// Check if the link was successful
		GLint success;
		GLchar info_log[512];
		glGetProgramiv(program_id, GL_LINK_STATUS, &success);
		if ( !success ) {
			glGetProgramInfoLog(program_id, 512, NULL, info_log);
			LogError("Shader Program linker error: %s", info_log);
			return false;
		}
		else {
			return (created = true);
		}
	}
	else return true;
}
void ShaderProgram::UseProgram() {
	if ( IsLinked() )
		glUseProgram(program_id);
}
void ShaderProgram::UnbindProgram() {
	glUseProgram(0);
}








void ShaderProgram::SetUniform(const string &name, float* values, int count) {
	int loc = glGetUniformLocation(program_id, name.c_str());
	glUniform1fv(loc, count, values);
}
void ShaderProgram::SetUniform(const string &name, const float value) {
	int loc = glGetUniformLocation(program_id, name.c_str());
	glUniform1fv(loc, 1, &value);
}
void ShaderProgram::SetUniform(const string &name, glm::vec2* vectors, int count) {
	int loc = glGetUniformLocation(program_id, name.c_str());
	glUniform2fv(loc, count, (GLfloat*)vectors);
}
void ShaderProgram::SetUniform(const string &name, const glm::vec2 &vector) {
	int loc = glGetUniformLocation(program_id, name.c_str());
	glUniform2fv(loc, 1, (GLfloat*)&vector);
}
void ShaderProgram::SetUniform(const string &name, glm::vec3* vectors, int count) {
	int loc = glGetUniformLocation(program_id, name.c_str());
	glUniform3fv(loc, count, (GLfloat*)vectors);
}
void ShaderProgram::SetUniform(const string &name, const glm::vec3 &vector) {
	int loc = glGetUniformLocation(program_id, name.c_str());
	glUniform3fv(loc, 1, (GLfloat*)&vector);
}
void ShaderProgram::SetUniform(const string &name, glm::vec4* vectors, int count) {
	int loc = glGetUniformLocation(program_id, name.c_str());
	glUniform4fv(loc, count, (GLfloat*)vectors);
}
void ShaderProgram::SetUniform(const string &name, const glm::vec4 &vector) {
	int loc = glGetUniformLocation(program_id, name.c_str());
	glUniform4fv(loc, 1, (GLfloat*)&vector);
}
void ShaderProgram::SetUniform(const string &name, glm::mat3* matrices, int count) {
	int loc = glGetUniformLocation(program_id, name.c_str());
	glUniformMatrix3fv(loc, count, false, (GLfloat*)matrices);
}
void ShaderProgram::SetUniform(const string &name, const glm::mat3 &matrix) {
	int loc = glGetUniformLocation(program_id, name.c_str());
	glUniformMatrix3fv(loc, 1, false, (GLfloat*)&matrix);
}
void ShaderProgram::SetUniform(const string &name, glm::mat4* matrices, int count) {
	int loc = glGetUniformLocation(program_id, name.c_str());
	glUniformMatrix4fv(loc, count, false, (GLfloat*)matrices);
}
void ShaderProgram::SetUniform(const string &name, const glm::mat4 &matrix) {
	int loc = glGetUniformLocation(program_id, name.c_str());
	glUniformMatrix4fv(loc, 1, false, (GLfloat*)&matrix);
}
void ShaderProgram::SetUniform(const string &name, int* values, int count) {
	int loc = glGetUniformLocation(program_id, name.c_str());
	glUniform1iv(loc, count, values);
}
void ShaderProgram::SetUniform(const string &name, const int value) {
	int loc = glGetUniformLocation(program_id, name.c_str());
	glUniform1i(loc, value);
}











