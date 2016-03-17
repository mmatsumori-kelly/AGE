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
#include <AGE/Thread.h>



using namespace age;
using namespace age::video;

using namespace shootergame;



Dimension::Dimension(World *world, const std::string &name) : world(world), name(name), shader_program() {
	save_folder = File(world->GetSaveFolder().GetChild(name));
	save_folder.MakeDirectory();
	GetChunksFolder().MakeDirectory();
	
	
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
	
}

Dimension* Dimension::Open(World *world, const std::string &name) {
	
	Dimension *dim = new Dimension(world, name);
	
	return dim;
}



void LoadChunkThread(void *chunk_out_ptrptr) {
	
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
		chunk->Save();
		delete chunk;
		
		loaded_chunks.erase(IntPair(x, z));
	}
}





void Dimension::Update(const age::UpdateInfo &info) {
	
	
}
void Dimension::Render(const age::UpdateInfo &info) {
	Player *player = GetWorld()->GetPlayer();
	FVec3 player_position = player->GetPosition();
	
	int chunk_x = (int)player_position.x / ChunkWidth;
	int chunk_z = (int)player_position.z / ChunkLength;
	
	// Bind necessary resources before rendering
	
	TextureAtlas<TEXTURE_ATLAS_BLOCK>::GetTexture()->BindTexture();
	shader_program.UseProgram();
	GetWorld()->GetSceneManager()->GetCamera()->Update();
	GetWorld()->GetSceneManager()->GetCamera()->UpdateProgram(&shader_program, FMat4(1.0f));
	
	
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






