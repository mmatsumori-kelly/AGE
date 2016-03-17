//
//  FPSCamera.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "FPSCamera.h"

using namespace age;
using namespace age::scene;
using namespace age::video;



FPSCamera::FPSCamera(float aspect_ratio, float fov, float near_z, float far_z)
: position(0, 0, 0), rotation(0, 0, 0), aspect_ratio(aspect_ratio), fov(fov), near_z(near_z), far_z(far_z) {
	CalculateMatrices();
}


void FPSCamera::NormalizeAngles() {
	rotation.x = fmodf(rotation.x, 360);
	rotation.y = fmodf(rotation.y, 360);
	rotation.z = fmodf(rotation.z, 360);
	
	if ( rotation.x > MAX_X_ROTATION ) rotation.x = MAX_X_ROTATION;
	else if ( rotation.x < -MAX_X_ROTATION ) rotation.x = -MAX_X_ROTATION;
}
void FPSCamera::CalculateOrientation() {
	glm::mat4 orientation(1.0f);
	
	// Rotate the matrix
	if ( rotation.x != 0 ) orientation = MatrixRotate(orientation, ToRadians(rotation.x), FVec3(1, 0, 0));
	if ( rotation.y != 0 ) orientation = MatrixRotate(orientation, ToRadians(rotation.y), FVec3(0, 1, 0));
	
	// Set the orientation
	this->orientation = orientation;
}
void FPSCamera::CalculateMatrices() {
	CalculateOrientation();
	
	view_matrix = orientation * MatrixTranslate(glm::mat4(), -position);
	projection_matrix = glm::perspective(45.0f, aspect_ratio, near_z, far_z);
	vp_matrix = projection_matrix * view_matrix;
}

void FPSCamera::Update() {
	
	NormalizeAngles();
	CalculateMatrices();
}
void FPSCamera::UpdateProgram(ShaderProgram *program, const FMat4 &model_matrix) {
	program->SetMVPMatrix(vp_matrix * model_matrix);
	program->SetViewMatrix(view_matrix);
	program->SetModelMatrix(model_matrix);
	program->SetCameraPosition(position);
	program->SetUniform("sampler", 0);
}



