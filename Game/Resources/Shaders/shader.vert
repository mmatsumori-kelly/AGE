#version 330 core

layout(location=0) in vec3 position_modelspace;
layout(location=1) in vec2 tex_coord;
layout(location=2) in vec3 normal_modelspace;
out vec2 uv;


uniform mat4 MVP;
uniform mat4 V;
uniform mat4 M;
uniform vec3 camera_position;

void main() {
	uv = tex_coord;
	gl_Position = MVP * vec4(position_modelspace, 1);
	
}


