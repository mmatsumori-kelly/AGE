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



World::World(const age::File &world_folder) : world_folder(world_folder) {
	
	
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
		for (auto dim : loaded_dimensions)
			if ( dim->GetName().compare(name) == 0 ) return dim;
		return nullptr;
	}
	else {
		Dimension *dim = Dimension::Open(this, name);
		loaded_dimensions.push_back(dim);
		
		return dim;
	}
}






void World::Update(const age::UpdateInfo &info) {
	for (auto dimension : loaded_dimensions)
		dimension->Update(info);
}
void World::Render(const age::UpdateInfo &info) {
	current_dimension->Render(info);
}









