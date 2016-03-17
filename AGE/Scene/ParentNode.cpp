//
//  ParentNode.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "ParentNode.h"

using namespace age::scene;






ParentNode::~ParentNode() {
	for (auto child : children) {
		delete child.second;
	}
	children.clear();
}


void ParentNode::Update(const age::UpdateInfo &info) {
	for (auto child : children) {
		child.second->Update(info);
	}
}
void ParentNode::Render(const age::UpdateInfo &info) {
	for (auto child : children) {
		child.second->Render(info);
	}
}



