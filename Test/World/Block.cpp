//
//  Block.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/7/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Block.h"
#include "TypeRegistry.h"
#include "Chunk.h"


using namespace age;
using namespace age::video;
using namespace age::scripting;
using namespace age::scene;
using namespace shootergame;





Block::Block(int type, Chunk *chunk, const age::IVec3 &position)
: block_id(type), chunk(chunk), position(position) {
	state = &GetBlockState(block_id);
	try {
//		is_solid = state->GetGlobal("IsSolid")(this);
		is_solid = true;
	} catch (...) {}
	
	
	float x = chunk->GetX() * ChunkWidth  + position.x;
	float z = chunk->GetZ() * ChunkLength + position.z;
	hitbox = AABBHitbox(FVec3(x + 0.5f, position.y + 0.5f, z + 0.5f), FVec3(0.5f, 0.5f, 0.5f));
}



int Block::GetAbsoluteX() {
	return chunk->GetCoords().x * ChunkWidth + GetX();
}
int Block::GetAbsoluteZ() {
	return chunk->GetCoords().y * ChunkLength + GetZ();
}

void Block::RemoveSelf() {
	chunk->SetBlock(position.x, position.y, position.z, nullptr);
}


void Block::AddRenderData(ManualModel *model) {
	state->GetGlobal("AddVertexData")(this, model);
}




