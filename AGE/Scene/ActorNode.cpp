//
//  ActorNode.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "ActorNode.h"
#include "../Video/SimpleModel.h"
#include "../Debug.h"
#include "SceneManager.h"

using namespace age;
using namespace age::scene;
using namespace age::video;



ActorNode::ActorNode() : shader(nullptr), model(nullptr), texture(nullptr), position(0, 0, 0), rotation(0, 0, 0) {
	
}
ActorNode::~ActorNode() {
	
}


void ActorNode::Update(const age::UpdateInfo &info) {
	
}
void ActorNode::Render(const age::UpdateInfo &info) {
	if ( model != nullptr && shader != nullptr ) {
		if ( texture != nullptr ) texture->BindTexture();
		
		// Build the model matrix
		FMat4 model_matrix(1.0f);
		if ( rotation.x != 0 ) model_matrix = MatrixRotate(model_matrix, rotation.x, FVec3(1, 0, 0));
		if ( rotation.y != 0 ) model_matrix = MatrixRotate(model_matrix, rotation.y, FVec3(0, 1, 0));
		if ( rotation.z != 0 ) model_matrix = MatrixRotate(model_matrix, rotation.z, FVec3(0, 0, 1));
		model_matrix = MatrixTranslate(model_matrix, position);
		
		// Do some stuff
		shader->UseProgram();
		GetParent()->GetSceneManager()->GetCamera()->Update();
		GetParent()->GetSceneManager()->GetCamera()->UpdateProgram(shader, model_matrix);
		
		// Render the model
		model->Render();
		
		// Unbind the texture and shader
		Texture::UnbindTexture();
		ShaderProgram::UnbindProgram();
	}
}




