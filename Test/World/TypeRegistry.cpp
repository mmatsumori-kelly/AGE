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
using namespace age::video;
using namespace age::scripting;
using namespace shootergame;



std::unordered_map<int, std::string> block_names;
std::unordered_map<int, LuaState*> block_states;



void shootergame::NewBlockType(int block_id, const std::string &name) {
	block_names[block_id] = name;
	LuaState *state = new LuaState();
	block_states[block_id] = state;
	LoadGameLibraries(*state);
	
	state->ExecFile(Game::Current()->GetScriptFolder().GetChild("Blocks").GetChild(name + ".lua"));
}

void shootergame::LoadRegistry() {
	
	// Load the blocks
	LuaState block_loader;
	block_loader.GetGlobalNamespace().addFunction("NewBlockType", shootergame::NewBlockType);
	block_loader.ExecFile(Game::Current()->GetScriptFolder().GetChild("Blocks").GetChild("BlockLoader.lua"));
	
	
}
void shootergame::UnloadRegistry() {
	
	// Delete every LuaState
//	for (auto state : block_states) delete state.second;
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





