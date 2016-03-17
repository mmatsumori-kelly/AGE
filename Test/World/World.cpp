//
//  World.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/28/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "World.h"
#include "TypeRegistry.h"
#include "TextureAtlas.h"
#include "../Game.h"
#include <AGE/Video/OBJModel.h>

using namespace age;
using namespace age::scene;
using namespace age::video;
using namespace shootergame;



World::World(const age::File &world_folder) : ParentNode(), world_folder(world_folder) {
	
	// Create and add the player
	player = new Player();
	this->AddChild("Player", player);
}

World* World::New(const age::File &world_folder) {
	world_folder.MakeDirectory();
	
	World *world = new World(world_folder);
	world->ChangeDimension("Earth");
	
	return world;
}
World* World::Load(const age::File &world_folder) {
	return nullptr;
}
World::~World() {
	
}




void World::ChangeDimension(const std::string &name) {
	
	// Make sure the dimension is loaded
	Dimension *dimension = LoadDimension(name);
	if ( dimension != nullptr ) current_dimension = dimension;
}
Dimension* World::LoadDimension(const std::string &name) {
	if ( IsDimensionLoaded(name) ) {
		return (Dimension*)GetChild(name);
	}
	else {
		Dimension *dim = Dimension::Open(this, name);
		AddChild(name, dim);
		return dim;
	}
}






void World::Update(const age::UpdateInfo &info) {
	ParentNode::Update(info);
	current_dimension->Update(info);
}
void World::Render(const age::UpdateInfo &info) {
	ParentNode::Render(info);
//	current_dimension->Render(info);
}









