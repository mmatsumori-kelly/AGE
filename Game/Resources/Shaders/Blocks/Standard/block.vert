#version 330 core

layout(location=0) in vec3 position_modelspace;
layout(location=1) in vec3 normal_modelspace;
layout(location=2) in vec2 tex_coord;


out vec2 uv;
out vec3 position_worldspace;
out vec3 normal_cameraspace;
out vec3 direction_cameraspace;

uniform mat4 MVP;
uniform mat4 V;
uniform mat4 M;
uniform vec3 camera_position;

void main() {
	gl_Position = MVP * vec4(position_modelspace, 1);
	position_worldspace = (M * vec4(position_modelspace, 1)).xyz;

	vec3 position_cameraspace = (V * M * vec4(position_modelspace, 1)).xyz;
	direction_cameraspace = camera_position - position_cameraspace;
	
	normal_cameraspace = (V * M * vec4(normal_modelspace, 1)).xyz;
	uv = tex_coord;
}


