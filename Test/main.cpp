//
//  main.cpp
//  Test
//
//  Created by Mitchell Matsumori-Kelly on 2/23/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Game.h"

using namespace age;
using namespace age::scene;
using namespace age::video;



int main(int argc, const char * argv[]) {
	using namespace age;
	
	
//	
//	AGEDevice *device = AGEDevice::New();
//	if ( device == nullptr )  return 1;
//	
//	device->GetDisplay()->SetTitle("ShooterGame");
//	device->GetDisplay()->Maximize();
//	
//	
//	
//	// Shader
//	ShaderSource *vert_source = ShaderSource::Load(File("/users/mmatsumori-kelly17/desktop/age/Game/Resources/Shaders/shader.vert"), AGE_SHADER_VERTEX);
//	ShaderSource *frag_source = ShaderSource::Load(File("/users/mmatsumori-kelly17/desktop/age/Game/Resources/Shaders/shader.frag"), AGE_SHADER_FRAGMENT);
//	ShaderProgram *program = new ShaderProgram();
//	program->AttachShader(vert_source);
//	program->AttachShader(frag_source);
//	program->LinkProgram();
//	delete vert_source;
//	delete frag_source;
//	
//	// Model
//	Handle<IModel> triangle_model = SimpleModel::Load(File("/users/mmatsumori-kelly17/desktop/age/Game/Resources/Models/model.smdl"));
//	
//	// Actor
//	Handle<ActorNode> triangle = new ActorNode();
//	triangle->SetModel(triangle_model);
//	triangle->SetShaderProgram(program);
//	
//	// Scene
//	SceneManager *scene_manager = device->GetSceneManager();
//	scene_manager->GetParentNode()->AddChild("Triangle", triangle);
//	
//	// Camera
//	IVec2 display_size = device->GetDisplay()->GetSize();
//	ICamera *cam = new FPSCamera(1.66, 45, 0, 1000.0f);
//	scene_manager->SetCamera(cam);
//	
//	
//	
//	
//	device->Start();
	
	
	shootergame::Game::Current()->Start();
	
	return 0;
}
