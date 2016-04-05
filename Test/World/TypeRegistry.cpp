//
//  BlockRegistry.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/8/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "TypeRegistry.h"
#include "../Game.h"
#include <unordered_map>
#include "../GameScripting.h"
#include <AGE/Scripting/LuaScript.h>

using namespace age;
using namespace age::scene;
using namespace age::video;
using namespace age::scripting;
using namespace shootergame;



std::unordered_map<int, std::string> block_names;
std::unordered_map<int, std::string> entity_names;
std::unordered_map<int, LuaState*> block_states;
std::unordered_map<int, LuaState*> entity_states;
std::unordered_map<int, CollisionShape*> block_collision_shapes;




void shootergame::NewBlockType(int block_id, const std::string &name) {
	LuaState *state = new LuaState();
	block_names [block_id] = name;
	block_states[block_id] = state;
	block_collision_shapes[block_id] = CollisionShape::NewBoxShape(FVec3(0.5f, 0.5f, 0.5f));
	
	// Scripting
	LoadGameLibraries(*state);
	state->ExecFile(Game::Current()->GetScriptFolder().GetChild("Blocks").GetChild(name + ".lua"));
}
void shootergame::NewEntityType(int entity_id, const std::string &name) {
	LuaState *state = new LuaState();
	entity_names [entity_id] = name;
	entity_states[entity_id] = state;
	
	// Scripting
	LoadGameLibraries(*state);
	state->ExecFile(Game::Current()->GetScriptFolder().GetChild("Entities").GetChild(name + ".lua"));
}

void shootergame::LoadRegistry() {
	
	// Load the blocks
	LuaState block_loader;
	block_loader.GetGlobalNamespace().addFunction("NewBlockType", shootergame::NewBlockType);
	block_loader.ExecFile(Game::Current()->GetScriptFolder().GetChild("Blocks/BlockLoader.lua"));
	
	// Load the entities
	LuaState entity_loader;
	entity_loader.GetGlobalNamespace().addFunction("NewEntityType", shootergame::NewEntityType);
	entity_loader.ExecFile(Game::Current()->GetScriptFolder().GetChild("Entities/EntityLoader.lua"));
	
}
void shootergame::UnloadRegistry() {
	
	// Delete all LuaStates
	for (auto state : block_states)  delete state.second;
	for (auto state : entity_states) delete state.second;
}



int shootergame::GetBlockID(const std::string &name) {
	for (auto pair : block_names)
		if ( pair.second.compare(name) == 0 ) return pair.first;
	return 0;
}
std::string shootergame::GetBlockName(int id) {
	return block_names[id];
}
LuaState& shootergame::GetBlockState(int block_id) {
	return *block_states[block_id];
}
LuaState& shootergame::GetEntityState(int entity_id) {
	return *entity_states[entity_id];
}
CollisionShape* shootergame::GetBlockCollisionShape(int block_id) {
	return block_collision_shapes[block_id];
}








