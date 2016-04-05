//
//  GameScripting.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/8/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "GameScripting.h"
#include <AGE/Video/IModel.h>
#include <AGE/Scene/ActorNode.h>
#include "Game.h"
#include "World/Entity/Entity.h"
#include "World/TextureAtlas.h"

using namespace age;
using namespace age::video;
using namespace age::scripting;
using namespace age::scene;
using namespace shootergame;


void LoadUtilLibrary(LuaState &state) {
	state.GetGlobalNamespace()
	.beginClass<VertexInfo>("Vertex")
	.addConstructor<void(*)(const FVec3&, const FVec3&, const FVec2&)>()
	.addData("vertex", &VertexInfo::vertex)
	.addData("normal", &VertexInfo::normal)
	.addData("uv", &VertexInfo::uv)
	.endClass()
	
	.beginClass<ManualModel>("Model")
	.addConstructor<void(*)(void)>()
	.addFunction("AddVertex", &ManualModel::AddVertexData)
	.endClass();

}
void LoadGameLibrary(LuaState &state) {
	state.SetGlobal("ChunkWidth", ChunkWidth);
	state.SetGlobal("ChunkHeight", ChunkHeight);
	state.SetGlobal("ChunkLength", ChunkLength);
	
	state.GetGlobalNamespace()
	
	.beginClass<Dimension>("Dimension")
	.addFunction("GetBlock", &Dimension::GetBlockByCoord)
	.addFunction("IsSolidBlock", &Dimension::IsSolidBlock)
	.endClass()
	
	
	.beginClass<Chunk>("Chunk")
	.addFunction("GetBlock", &Chunk::GetBlock)
	.addFunction("IsSolidBlock", &Chunk::IsSolidBlock)
	.addFunction("GetDimension", &Chunk::GetDimension)
	.addFunction("GetX", &Chunk::GetX)
	.addFunction("GetZ", &Chunk::GetZ)
	.endClass()
	
	
	.beginClass<Block>("Block")
	.addFunction("GetX", &Block::GetX)
	.addFunction("GetY", &Block::GetY)
	.addFunction("GetZ", &Block::GetZ)
	.addFunction("GetAbsX", &Block::GetAbsoluteX)
	.addFunction("GetAbsZ", &Block::GetAbsoluteZ)
	.addFunction("IsSolid", &Block::IsSolid)
	.addFunction("GetChunk", &Block::GetChunk)
	.endClass()
	
	.beginClass<Entity>("Entity")
	.addFunction("GetPosition", &Entity::GetPosition)
	.addFunction("GetRotation", &Entity::GetRotation)
	.addFunction("SetPosition", &Entity::SetPosition)
	.addFunction("SetRotation", &Entity::SetRotation)
	.endClass()
	
	
	
	.beginClass<TextureAtlas<TEXTURE_ATLAS_BLOCK>>("BlockTexture")
	.addStaticFunction("GetTexCoord", &TextureAtlas<TEXTURE_ATLAS_BLOCK>::GetTextureCoords)
	;
}




/** Loads game libraries for a given state */
void shootergame::LoadGameLibraries(LuaState &state) {
	
	// Add game folders
	state["game_folder"] = Game::Current()->GetGameFolder().GetPath().c_str();
	state["model_folder"] = Game::Current()->GetModelFolder().GetPath().c_str();
	state["shader_folder"] = Game::Current()->GetShaderFolder().GetPath().c_str();
	state["script_folder"] = Game::Current()->GetScriptFolder().GetPath().c_str();
	state["texture_folder"] = Game::Current()->GetTextureFolder().GetPath().c_str();
	
	
	// Add some other stuff
	state.SetGlobal("display", Game::Current()->GetDevice()->GetDisplay());
	state.SetGlobal("scene_manager", Game::Current()->GetDevice()->GetSceneManager());
	
	
	// Register some stuff for Lua
	LoadUtilLibrary(state);
	LoadGameLibrary(state);
	
	
	
}





