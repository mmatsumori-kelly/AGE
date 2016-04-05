//
//  BlockRegistry.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/8/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__BlockRegistry__
#define __AGE__BlockRegistry__

#include <AGE/Scene/PhysicsWorld.h>
#include <AGE/Scripting/LuaScript.h>
#include <AGE/Video/Shader.h>
#include <AGE/Video/IModel.h>
#include <AGE/Video/Texture.h>

namespace shootergame {
	
	
	/** Creates a new block type */
	void NewBlockType(int block_id, const std::string &name);
	/** Creates a new block type */
	void NewEntityType(int entity_id, const std::string &name);
	
	
	
	
	/** Loads the block registry */
	void LoadRegistry();
	/** Unloads the registry */
	void UnloadRegistry();
	
	
	
	
	/** Returns a block id, given a name */
	int GetBlockID(const std::string &name);
	/** Returns a block's collision shape */
	age::scene::CollisionShape* GetBlockCollisionShape(int block_id);
	/** Returns a block name, given an id */
	std::string GetBlockName(int id);
	
	
	/** Returns a block state, given a block id */
	age::scripting::LuaState& GetBlockState(int block_id);
	/** Returns a block state, given a block id */
	age::scripting::LuaState& GetEntityState(int entity_id);
	
	
	
	
	
}

#endif /* defined(__AGE__BlockRegistry__) */
