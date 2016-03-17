//
//  Dimension.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/28/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Dimension__
#define __AGE__Dimension__

#include "Chunk.h"
#include <unordered_map>


namespace std {
	template <typename a, typename b>
	struct hash<std::pair<a, b>> {
	private:
		const hash<a> ah;
		const hash<b> bh;
	public:
		inline hash() : ah(), bh() {
			
		}
		size_t operator()(const std::pair<a, b> &p) const {
			size_t seed = 0;
			seed ^= ah(p.first)  + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			seed ^= bh(p.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			return seed;
//			return (p.first + p.second) * (p.first + p.second + 1) + 2 * p.second;
		}
	};
}

namespace shootergame {
	class World;
	
	typedef std::pair<int, int> IntPair;
	
	
	/** Dimension in a world */
	class Dimension : public age::scene::ISceneNode {
		World *world;
		std::string name;
		age::File save_folder;
		
		age::video::ShaderProgram shader_program;
		
		std::unordered_map<IntPair, Chunk*, std::hash<IntPair>> loaded_chunks;
		
		
		
		Dimension(World *world, const std::string &name);
		
		inline std::string GetChunkString(int x, int z) {
			return std::to_string(x) + "x" + std::to_string(z);
		}
		
		
	public:
		static Dimension* Open(World *world, const std::string &name);
		~Dimension();
		
		
		/** Returns the world containing this dimension */
		inline World* GetWorld() const {
			return world;
		}
		/** Returns the name of this dimension */
		inline const std::string& GetName() const {
			return name;
		}
		/** Returns the save folder for this dimension */
		inline const age::File& GetSaveFolder() const {
			return save_folder;
		}
		/** Returns the chunks folder */
		inline age::File GetChunksFolder() const {
			return GetSaveFolder().GetChild("Chunks");
		}
		/** Returns this dimension's shader program */
		inline age::video::ShaderProgram* GetShaderProgram() {
			return &shader_program;
		}
		
		
		
		/** Loads the chunk by coords */
		Chunk* LoadChunk(int x, int z);
		/** Unloads the chunk by coords */
		void UnloadChunk(int x, int z);
		/** Returns a chunk by coords */
		inline Chunk* GetChunk(int x, int z, bool load = true) {
			if ( IsChunkLoaded(x, z) ) return loaded_chunks[IntPair(x, z)];
			else {
				if ( load ) return LoadChunk(x, z);
				else return nullptr;
			}
		}
		/** Checks if a chunk is loaded */
		inline bool IsChunkLoaded(int x, int z) {
			return loaded_chunks.count(IntPair(x, z)) != 0;
		}
		/** Checks if a chunk is generated */
		inline bool IsChunkGenerated(int x, int z) {
			return GetChunksFolder().GetChild(GetChunkString(x, z) + ".chk").Exists();
		}
		/** Returns a chunk, given the block coordinates */
		inline Chunk* GetChunkByBlockCoord(float x, float z, bool load = false) {
			int chunk_x = (int)floor(x / ChunkWidth), chunk_z = (int)floor(z / ChunkLength);
			return GetChunk(chunk_x, chunk_z, load);
		}
		/** Returns a block at the given coordinates */
		inline Block* GetBlockByCoord(long x, long y, long z, bool load = false) {
			int rel_x = (x < 0) ? (ChunkWidth  + x % ChunkWidth)  : (x % ChunkWidth);
			int rel_z = (z < 0) ? (ChunkLength + z % ChunkLength) : (z % ChunkLength);
			
			Chunk* reg = GetChunkByBlockCoord(x, z, load);
			if ( reg == nullptr ) return nullptr;
			else return reg->GetBlock(rel_x, (int)y, rel_z);
			
		}
		/** Checks if a given block is solid */
		inline bool IsSolidBlock(float x, float y, float z, bool load = false) {
			Block *b = GetBlockByCoord(x, y, z, load);
			return (b == nullptr) ? false : b->IsSolid();
		}
		
		
		
		virtual void Update(const age::UpdateInfo &info) override;
		virtual void Render(const age::UpdateInfo &info) override;
		
	};
	
	
}

#endif /* defined(__AGE__Dimension__) */
