//
//  Chunk.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/28/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Chunk__
#define __AGE__Chunk__

#include "AGE.h"
#include "File.h"
#include "Block.h"

namespace shootergame {
	class Dimension;

	const static int SectorHeight = 16, NumSectors = 8;
	const static int ChunkWidth = 16, ChunkLength = 16, ChunkHeight = SectorHeight * NumSectors;
	
	
	class Chunk {
		age::IVec2 chunk_coords;
		
		Dimension *dimension;
		age::File chunk_file;
		
		Block *blocks[ChunkWidth][ChunkHeight][ChunkLength] = { nullptr };
		age::video::ManualModel *sector_models[NumSectors]  = { nullptr };
		
		
		bool is_loading; // Is the chunk currently loading?
		age::Thread *loading_thread;
		
		
		
		static inline std::string GetChunkString(int x, int z) {
			return std::to_string(x) + "x" + std::to_string(z);
		}
		Chunk(Dimension *dimension, const age::IVec2 &coords);
		
		
		static void GenerateChunk(void *chunk);
		void Generate();
		void Load();
		
	public:
		~Chunk();
		static Chunk* Open(Dimension *parent, const age::IVec2 &coords);
		/** Saves the chunk */
		void Save();
		
		
		/** Returns the chunk coordinates */
		inline const age::IVec2& GetCoords() const {
			return chunk_coords;
		}
		/** Returns the x-coodinate of this chunk */
		inline int GetX() const {
			return chunk_coords.x;
		}
		/** Returns the z-coodinate of this chunk */
		inline int GetZ() const {
			return chunk_coords.y;
		}
		/** Returns the parent dimension */
		inline Dimension* GetDimension() {
			return dimension;
		}
		/** Returns the chunk file */
		inline const age::File& GetChunkFile() const {
			return chunk_file;
		}
		/** Checks if the chunk is currently loading */
		inline bool IsLoading() const {
			return is_loading;
		}
		
		
		/** Returns the blocks */
		inline void GetBlocks(Block *blocks_out[ChunkWidth][ChunkHeight][ChunkLength]) {
			blocks_out = blocks;
		}
		/** Returns a block */
		inline Block* GetBlock(int x, int y, int z) {
			return (x < 0 || x >= ChunkWidth || y < 0 || y >= ChunkHeight || z < 0 || z >= ChunkLength) ? nullptr : blocks[x][y][z];
		}
		/** Sets a block */
		inline void SetBlock(int x, int y, int z, Block *block);
		/** Checks if the given block is solid */
		inline bool IsSolidBlock(int x, int y, int z) {
			Block *block = GetBlock(x, y, z);
			if ( block == nullptr ) return false;
			else return block->IsSolid();
		}
		
		
		
		/** Generates the model for a given sector */
		void RegenerateSectorModel(int sector);
		/** Generates the model for a given sector */
		inline void RegenerateSectorModel(const age::IVec3 &coord) {
			RegenerateSectorModel(coord.y / SectorHeight);
		}
		
		
		void Update(const age::UpdateInfo &info);
		void Render(const age::UpdateInfo &info);
		
	};
	
	
	
	
	
	
}

#endif /* defined(__AGE__Chunk__) */
