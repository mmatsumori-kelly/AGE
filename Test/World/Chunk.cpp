//
//  Chunk.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/28/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Chunk.h"
#include "Dimension.h"
#include <AGE/Thread.h>

using namespace age;
using namespace age::scene;
using namespace age::video;
using namespace shootergame;



Chunk::Chunk(Dimension *dimension, const age::IVec2 &coords)
: dimension(dimension), chunk_coords(coords), is_loading(true), loading_thread(nullptr) {
	chunk_file = dimension->GetChunksFolder().GetChild(GetChunkString(coords.x, coords.y) + ".chk");
}
Chunk::~Chunk() {
	for (int x = 0; x < ChunkWidth; ++x) for (int y = 0; y < ChunkHeight; ++y) for (int z = 0; z < ChunkLength; ++z)
		delete blocks[x][y][z];
}



void Chunk::GenerateChunk(void *c) {
	Chunk *chunk = (Chunk*)c;
	chunk->Generate();
}


Chunk* Chunk::Open(shootergame::Dimension *parent, const age::IVec2 &coords) {
	File chunk_file = parent->GetChunksFolder().GetChild(GetChunkString(coords.x, coords.y) + ".chk");
	
	
	// Generate the chunk
	if ( !chunk_file.Exists() ) {
		Chunk *chunk = new Chunk(parent, coords);
		
		chunk->Generate();
//		chunk->loading_thread = new Thread();
//		chunk->loading_thread->Start(GenerateChunk, chunk, false);
		
		
		return chunk;
	}
	// Load the chunk
	else {
		
		
		
		return nullptr;
	}
}

void Chunk::Generate() {
	is_loading = true;
	for (int y = 0; y < 20; ++y) for (int x = 0; x < ChunkWidth; ++x) for (int z = 0; z < ChunkLength; ++z) {
		SetBlock(x, y, z, new Block( (y < 19 ? 1 : 0), this, IVec3(x, y, z)));
	}
//	Save();
	is_loading = false;
}
void Chunk::Load() {
	FileInputStream input_stream;
}
void Chunk::Save() {
	
	
	FileOutputStream output_stream;
	bool success = output_stream.Open(chunk_file);
	if ( success ) {
		
		// Write coordinates
		
		
	}
	else error << "Failed to open chunk stream for saving" << endline;
	
}



void Chunk::SetBlock(int x, int y, int z, shootergame::Block *block) {
	if ( blocks[x][y][z] != nullptr ) delete blocks[x][y][z];
	blocks[x][y][z] = block;
}



void Chunk::RegenerateSectorModel(int sector) {
	
	// Destroy the old model
	delete sector_models[sector];
	sector_models[sector] = new ManualModel();
	
	// Create the new model
	for (int y = sector * SectorHeight; y < (sector + 1) * SectorHeight; ++y)
		for (int x = 0; x < ChunkWidth; ++x) for (int z = 0; z < ChunkLength; ++z) {
			if ( blocks[x][y][z] != nullptr )
				blocks[x][y][z]->AddRenderData(sector_models[sector]);
		}
	
	
	sector_models[sector]->Create();
}


void Chunk::Update(const age::UpdateInfo &info) {
	
}
void Chunk::Render(const age::UpdateInfo &info) {
	if ( !IsLoading() ) {
		
		
		for (int y = 0; y < NumSectors; ++y) {
			
			if ( sector_models[y] == nullptr ) RegenerateSectorModel(y);
			sector_models[y]->Render();
		}
	}
}




