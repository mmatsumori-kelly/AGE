//
//  Dimension.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/28/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Dimension.h"
#include "World.h"
#include "../Game.h"
#include "TypeRegistry.h"
#include "TextureAtlas.h"
#include "Entity/Player.h"



using namespace age;
using namespace age::scene;
using namespace age::video;
using namespace shootergame;



Dimension::Dimension(World *world, const std::string &name)
: world(world), name(name), shader_program(), gravity(0, -12.0f, 0) {
	save_folder = File(world->GetSaveFolder().GetChild(name));
	save_folder.MakeDirectory();
	GetChunksFolder().MakeDirectory();
	
	// Entities
	entities.reserve(128);
	
	player = new Player(this);
	AddEntity(player);
	
	
	// Load the shaders
	ShaderSource *vert_source = ShaderSource::Load(Game::Current()->GetShaderFolder().GetChild("shader.vert"), AGE_SHADER_VERTEX);
	ShaderSource *frag_source = ShaderSource::Load(Game::Current()->GetShaderFolder().GetChild("shader.frag"), AGE_SHADER_FRAGMENT);
	shader_program.AttachShader(vert_source);
	shader_program.AttachShader(frag_source);
	shader_program.LinkProgram();
	delete vert_source;
	delete frag_source;
}
Dimension::~Dimension() {
	for (auto chunk : loaded_chunks) {
		delete chunk.second;
	}
}
Dimension* Dimension::Open(World *world, const std::string &name) {
	return new Dimension(world, name);
}


void Dimension::AddEntity(shootergame::Entity *e) {
	entities.push_back(e);
}




Chunk* Dimension::LoadChunk(int x, int z) {
	if ( IsChunkLoaded(x, z) ) return GetChunk(x, z, false);
	else {
		
		// Load the chunk
		Chunk *chunk = Chunk::Open(this, IVec2(x, z));
		loaded_chunks[IntPair(x, z)] = chunk;
		
		return chunk;
	}
}
void Dimension::UnloadChunk(int x, int z) {
	if ( IsChunkLoaded(x, z) ) {
		
		// Delete the chunk
		Chunk *chunk = GetChunk(x, z, false);
//		chunk->Save();
		delete chunk;
		
		loaded_chunks.erase(IntPair(x, z));
	}
}





void Dimension::Update(const age::UpdateInfo &info) {
	
	for (Entity *e : entities)
		e->Update(info);
	
	
}
void Dimension::Render(const age::UpdateInfo &info) {
	
	
	for (Entity *e : entities)
		e->Render(info);
	
	
	
	FVec3 player_position = player->GetPosition();
	
	int chunk_x = (int)player_position.x / ChunkWidth;
	int chunk_z = (int)player_position.z / ChunkLength;
	
	// Bind necessary resources before rendering
	
	TextureAtlas<TEXTURE_ATLAS_BLOCK>::GetTexture()->BindTexture();
	shader_program.UseProgram();
	Game::Current()->GetDevice()->GetSceneManager()->GetCamera()->Update();
	Game::Current()->GetDevice()->GetSceneManager()->GetCamera()->UpdateProgram(&shader_program, FMat4(1.0f));
	
	
	for (int x = chunk_x - 1; x < chunk_x + 1; ++x) {
		for (int z = chunk_z - 1; z < chunk_z + 1; ++z) {
			// Render the chunk
			Chunk *chunk = GetChunk(x, z, true);
			chunk->Render(info);
		}
	}
	
	
	// Unbind any previously bound resources
	shader_program.UnbindProgram();
	Texture::UnbindTexture();
}






