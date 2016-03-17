//
//  SceneManager.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/22/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "SceneManager.h"

using namespace age;
using namespace age::scene;





SceneManager::SceneManager(AGEDevice *device) : device(device), camera(nullptr) {
	parent_node = new ParentNode();
	parent_node->scene_manager = this;
}
SceneManager::~SceneManager() {
	delete parent_node;
	delete camera;
}





void SceneManager::Update(const age::UpdateInfo &info) {
	parent_node->Update(info);
}
void SceneManager::Render(const age::UpdateInfo &info) {
	if ( camera != nullptr )
		camera->Update();
	parent_node->Render(info);
}







