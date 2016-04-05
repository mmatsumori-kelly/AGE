//
//  Block.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/7/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Block__
#define __AGE__Block__

#include <AGE/Vector.h>
#include <AGE/Debug.h>
#include <AGE/Video/ManualModel.h>
#include <AGE/Scripting/LuaScript.h>
#include "Hitbox.h"


namespace shootergame {
	class Chunk;
	
	/** A block in the world */
	class Block {
		int block_id;
		age::IVec3 position;
		age::scripting::LuaState *state;
		Chunk *chunk;
		
		bool is_solid;
		
		AABBHitbox hitbox;
		
	public:
		
		Block(int type, Chunk *chunk, const age::IVec3 &position);
		
		
		
		
		/** Returns the chunk */
		inline Chunk* GetChunk() {
			return chunk;
		}
		
		/** Returns the hitbox */
		inline const AABBHitbox& GetHitbox() const {
			return hitbox;
		}
		
		
		
		/** Return the position */
		inline const age::IVec3& GetPosition() {
			return position;
		}
		/** Return the x coordinate */
		inline int GetX() {
			return position.x;
		}
		/** Return the y coordinate */
		inline int GetY() {
			return position.y;
		}
		/** Return the z coordinate */
		inline int GetZ() {
			return position.z;
		}
		int GetAbsoluteX();
		int GetAbsoluteZ();
		
		
		/** Checks if the block is solid */
		inline bool IsSolid() const {
			return is_solid;
		}
		
		
		void AddRenderData(age::video::ManualModel *model);
		
	};
	
}

#endif /* defined(__AGE__Block__) */
